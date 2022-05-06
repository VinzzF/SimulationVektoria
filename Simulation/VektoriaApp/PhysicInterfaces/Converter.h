#pragma once
#include "VektoriaMath/HVector.h"

#include <glm/glm.hpp>

static Vektoria::CHVector convertVector(const glm::vec3& vec, float w = 1.0f)
{
	return Vektoria::CHVector(vec.x, vec.y, vec.z, w);
}

static glm::vec3 convertVector(const Vektoria::CHVector& vec)
{
	return glm::vec3(vec.x, vec.y, vec.z);
}