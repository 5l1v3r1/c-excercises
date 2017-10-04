#include "surface_3d.h"

#include <algorithm>

namespace Display {

using Math::Vector4D;

Surface3D::Surface3D(Surface2D& surface2D)
:	mSurface(surface2D)
{
	auto dimensions = surface2D.GetDimensions();
	camera.SetAspectRatio(dimensions[0] / static_cast<float>(dimensions[1]));
}

void Surface3D::DrawTriangle(const Triangle3D& triangle, Color color)
{
	auto angle = std::min(0.0f, triangle.GetSurfaceNormal().Dot({0.0f, 0.0f, 1.0f}));

	auto halfColor = color * 0.5f;
	auto shadedColor = halfColor + halfColor * -angle;

	mSurface.DrawTriangle(Project(triangle), shadedColor);
}

void Surface3D::DrawTriangles(const std::vector<Triangle3D>& triangles, Color color)
{
	for(auto& triangle : triangles)
		DrawTriangle(triangle, color);
}

Vector2D Surface3D::Project(Vector3D vector) const
{
	auto clipSpace = camera.GetProjectionMatrix() * Vector4D{vector, 1.0f};
	return {clipSpace[0] / clipSpace[3], clipSpace[1] / clipSpace[3]};
}

Triangle2D Surface3D::Project(Triangle3D triangle) const
{
	return {
		Project(triangle[0]),
		Project(triangle[1]),
		Project(triangle[2])
	};
}

}
