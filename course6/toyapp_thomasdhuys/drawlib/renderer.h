#pragma once

#include <cstdint>
#include <vector>

#include <displaylib/surface.h>
#include <displaylib/window.h>
#include <displaylib/functions.h>

#include "primitives.h"
#include "render_object.h"

namespace Draw {
namespace Render {

class Renderer {
public:
	Renderer();
	void Render(RenderObject ro);
private:
	static Display::Window DefaultWindow();
	static Display::Surface DefaultSurface();
	Display::Window window;
	Display::Surface surface;
};

}
}
