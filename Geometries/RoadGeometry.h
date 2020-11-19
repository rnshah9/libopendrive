#pragma once

#include <array>
#include <map>
#include <memory>
#include <string>

#include "../Utils.hpp"

namespace odr
{
class Road;

enum class GeometryType
{
    Line,
    Spiral,
    Arc,
    ParamPoly3
};

struct RoadGeometry
{
    RoadGeometry(double s0, double x0, double y0, double hdg0, double length, GeometryType type, std::shared_ptr<Road> road);
    virtual ~RoadGeometry();

    virtual void update() = 0;

    virtual Vec2D get_xy(double s) const = 0;
    virtual Vec2D get_grad(double s) const = 0;

    double s0;
    double x0;
    double y0;
    double hdg0;
    double length;

    GeometryType          type;
    std::shared_ptr<Road> road;
    Box2D                 bounding_box;
};

using RoadGeometrySet = std::set<std::shared_ptr<RoadGeometry>, SharedPtrCmp<RoadGeometry, double, &RoadGeometry::s0>>;

} // namespace odr
