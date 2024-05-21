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

	void rasterizeTriangle(SDL_Renderer *renderer, const std::vector<egc::vec4> &triangleVertices, const std::vector<egc::vec4> &triangleColors) {
		//TO DO - Implement the triangle rasterization algorithm


	}

}