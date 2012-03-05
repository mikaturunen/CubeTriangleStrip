#ifndef CUBETRIANGLESTRIP_HPP
#define CUBETRIANGLESTRIP_HPP

#include <vector>
#include <algorithm>
#include <iterator>

namespace Utilities {
	// dummy Vector 3D struct to make internal usage and understandability of CreateTriangleStrip easier
	struct V3 {
		float x, y, z;

		V3(const float &x, const float &y, const float &z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};


	class Cube {
	public:
		/*!
			Creates a cube as Triangle strip. 
			@param size
				Size of the Cube.
			@param antiClockwise
				If the vertices are defined in anti-clockwise manner.
			@return
				std::vector containing floats (x,y,z,  x,y,z,  x,y,z ...) for easier rendering.
		*/
		static inline std::vector<float> CreateTriangleStrip(const float &size, const bool &antiClockwise) {
			// half-size
			const float x = size / 2.0f;			
			const float y = x;
			const float z = x;
	
			// 8 vertices for cube
			std::vector<V3> cube;
			cube.push_back(V3(x, -y, -z));
			cube.push_back(V3(x, y, -z));
			cube.push_back(V3(-x, y, -z));
			cube.push_back(V3(-x, -y, -z));
			cube.push_back(V3(x, -y, z));
			cube.push_back(V3(x, y, z));
			cube.push_back(V3(-x, y, z));
			cube.push_back(V3(-x, -y, z));

			// triangulate the cube using the pre-defined cube vertices
			std::vector<V3> vertices;
			vertices.push_back(V3(cube[6]));
			vertices.push_back(V3(cube[5]));
			vertices.push_back(V3(cube[2]));
			vertices.push_back(V3(cube[1]));
			vertices.push_back(V3(cube[0]));
			vertices.push_back(V3(cube[5]));
			vertices.push_back(V3(cube[4]));
			vertices.push_back(V3(cube[6]));
			vertices.push_back(V3(cube[7]));
			vertices.push_back(V3(cube[2]));
			vertices.push_back(V3(cube[3]));
			vertices.push_back(V3(cube[0]));
			vertices.push_back(V3(cube[7]));
			vertices.push_back(V3(cube[4]));

			// wanted in anti-clockwise order
			if( antiClockwise ) {
				std::reverse(vertices.begin(), vertices.end());
			}

			// convert to float vector the opengl can digest 
			std::vector<float> vertexData;
			for(std::vector<V3>::iterator i=vertices.begin(); i!=vertices.end(); i++) {
				V3 v = *i;
				vertexData.push_back(v.x);
				vertexData.push_back(v.y);
				vertexData.push_back(v.z);
			}

			return vertexData;
		}
	};
}

#endif