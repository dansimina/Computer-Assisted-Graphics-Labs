#include "rasterization.h"

namespace egc {


	void computeAlphaBetaGamma(const std::vector<egc::vec4>& triangleVertices, vec2 pixel, float& alpha, float& beta, float& gamma) 
	{
		//TODO - Compute alfa, beta and gamma => we use the function's input parameters as the return mechanism
		//Store the final results in the input parameters

	}

	void rasterizeTriangle(SDL_Renderer *renderer, const std::vector<egc::vec4> &triangleVertices, const std::vector<egc::vec4> &triangleColors) {
		//TODO - Implement the triangle rasterization algorithm with the Z-Buffer algorithm
		//depthBuffer is declared as an external global variable in main.cpp and thus can be accessed here as depthBuffer[i][j]

	}

	void clearDepthBuffer() {
		//TODO - Implement clearing the depth buffer
		//depthBuffer is declared as an external global variable in main.cpp and thus can be accessed here as depthBuffer[i][j]

	}

}