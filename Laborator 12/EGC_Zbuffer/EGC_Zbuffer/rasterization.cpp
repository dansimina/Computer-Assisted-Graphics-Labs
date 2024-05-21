#include "rasterization.h"

namespace egc {


	void computeAlphaBetaGamma(const std::vector<egc::vec4>& triangleVertices, vec2 pixel, float& alpha, float& beta, float& gamma)
	{
		//TO DO - Compute alfa, beta and gamma => we use the function's input parameters as the return mechanism
		//Store the final results in the input parameters

		alpha = ((triangleVertices[1].y - triangleVertices[2].y) * pixel.x + (triangleVertices[2].x - triangleVertices[1].x) * pixel.y + triangleVertices[1].x * triangleVertices[2].y - triangleVertices[2].x * triangleVertices[1].y) / ((triangleVertices[1].y - triangleVertices[2].y) * triangleVertices[0].x + (triangleVertices[2].x - triangleVertices[1].x) * triangleVertices[0].y + triangleVertices[1].x * triangleVertices[2].y - triangleVertices[2].x * triangleVertices[1].y);
		beta = ((triangleVertices[2].y - triangleVertices[0].y) * pixel.x + (triangleVertices[0].x - triangleVertices[2].x) * pixel.y + triangleVertices[2].x * triangleVertices[0].y - triangleVertices[0].x * triangleVertices[2].y) / ((triangleVertices[2].y - triangleVertices[0].y) * triangleVertices[1].x + (triangleVertices[0].x - triangleVertices[2].x) * triangleVertices[1].y + triangleVertices[2].x * triangleVertices[0].y - triangleVertices[0].x * triangleVertices[2].y);
		gamma = 1 - alpha - beta;
	}

	struct MyBoundingBox
	{
		float minX;
		float minY;
		float maxX;
		float maxY;
	};

	MyBoundingBox findBoundingBox(const std::vector<egc::vec4>& triangleVertices) {
		MyBoundingBox boundingBox;
		boundingBox.minX = triangleVertices[0].x;
		boundingBox.minY = triangleVertices[0].y;
		boundingBox.maxX = triangleVertices[0].x;
		boundingBox.maxY = triangleVertices[0].y;

		for (int i = 1; i < triangleVertices.size(); i++) {
			boundingBox.minX = std::min(boundingBox.minX, triangleVertices[i].x);
			boundingBox.minY = std::min(boundingBox.minY, triangleVertices[i].y);
			boundingBox.maxX = std::max(boundingBox.maxX, triangleVertices[i].x);
			boundingBox.maxY = std::max(boundingBox.maxY, triangleVertices[i].y);
		}

		return boundingBox;
	}

	void rasterizeTriangle(SDL_Renderer* renderer, const std::vector<egc::vec4>& triangleVertices, const std::vector<egc::vec4>& triangleColors) {
		//TO DO - Implement the triangle rasterization algorithm

		MyBoundingBox boundingBox = findBoundingBox(triangleVertices);
		for (int x = boundingBox.minX; x <= boundingBox.maxX; x++) {
			for (int y = boundingBox.minY; y <= boundingBox.maxY; y++) {
				vec2 pixel = vec2(x, y);

				float alpha, beta, gamma;
				computeAlphaBetaGamma(triangleVertices, pixel, alpha, beta, gamma);

				if (alpha > 0 and alpha < 1 and beta > 0 and beta < 1 and gamma > 0 and gamma < 1) {

					float z = triangleVertices[0].z * triangleVertices[1].z * triangleVertices[2].z;

					if (z > depthBuffer[x][y]) {
						depthBuffer[x][y] = z;
						egc::vec4 finalColor = triangleColors[0] * alpha;
						finalColor += triangleColors[1] * beta;
						finalColor += triangleColors[2] * gamma;
						SDL_SetRenderDrawColor(renderer, finalColor.x, finalColor.y, finalColor.z, finalColor.w);
						SDL_RenderDrawPoint(renderer, x, y);
					}
				}
			}
		}
	}


	void clearDepthBuffer() {
		//TODO - Implement clearing the depth buffer
		//depthBuffer is declared as an external global variable in main.cpp and thus can be accessed here as depthBuffer[i][j]
		
		for (int x = 0; x < WINDOW_WIDTH; x++) {
			for (int y = 0; y < WINDOW_HEIGHT; y++) {
				depthBuffer[x][y] = -1.0f;
			}
		}
	}

}