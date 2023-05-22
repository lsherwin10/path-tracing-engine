#ifndef MATERIALS_H
#define MATERIALS_H

#include "factory.h"
#include "vector3.h"

/*
Translucence
Transparence
Opacity
Reflectivity
Glossiness
*/

// TODO: implement visitor pattern for materials (visit = ray bounce)

namespace mpcs51045 {

class Material {
   public:
    Material(Vector3<double> const &c) : mat_color(c) {}
    virtual ~Material() = default;

    virtual double reflectivity() = 0;
    virtual double luminosity() = 0;
    Vector3<double> color() { return mat_color; }

   private:
    Vector3<double> mat_color;
};

class Glossy : public Material {
   public:
    Glossy(Vector3<double> c) : Material(c) {}

    double reflectivity() { return 0.9; }
    double luminosity() { return 0.0; }
};

class Matte : public Material {
   public:
    Matte(Vector3<double> c) : Material(c) {}

    double reflectivity() { return 0.1; }
    double luminosity() { return 0.0; }
};

class Light : public Material {
   public:
    Light(Vector3<double> c) : Material(c) {}

    double reflectivity() { return 0.0; }
    double luminosity() { return 0.9; }
};

using AbstractMaterialFactory = mpcs51045::abstract_factory<Material>;
using MaterialFactory = mpcs51045::concrete_factory<AbstractMaterialFactory,
                                                    Glossy, Matte>;

}  // namespace mpcs51045

#endif