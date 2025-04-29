#include "particle.hpp"

#define X_INTERVAL 1.0
#define Y_INTERVAL 1.0
#define Z_INTERVAL 1.0

Particle::Particle() {}
Particle::~Particle() {}

void Particle::applyForce(Vec3D f) {
    acc = acc + f;
}

void Particle::update() {
    Vec3D vel = pos - prv;
    prv = pos;
    pos = pos + vel + acc / mass;
    acc = {0, 0, 0};
}

void Particle::keepWithinBounds() {
    // Periodic Boundaries
    if (pos.x < -X_INTERVAL) {
        pos.x += 2 * X_INTERVAL;
        prv.x += 2 * X_INTERVAL;
    } else if (pos.x > X_INTERVAL) {
        pos.x -= 2 * X_INTERVAL;
        prv.x -= 2 * X_INTERVAL;
    }

    if (pos.y < -Y_INTERVAL) {
        pos.y += 2 * Y_INTERVAL;
        prv.y += 2 * Y_INTERVAL;
    } else if (pos.y > Y_INTERVAL) {
        pos.y -= 2 * Y_INTERVAL;
        prv.y -= 2 * Y_INTERVAL;
    }

    if (pos.z < -Z_INTERVAL) {
        pos.z += 2 * Z_INTERVAL;
        prv.z += 2 * Z_INTERVAL;
    } else if (pos.z > Z_INTERVAL) {
        pos.z -= 2 * Z_INTERVAL;
        prv.z -= 2 * Z_INTERVAL;
    }
}