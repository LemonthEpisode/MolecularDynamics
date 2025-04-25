typedef struct {
    double x, y, z;
} Vec3D;

Vec3D operator + (Vec3D A, Vec3D B) {
    return (Vec3D) {A.x+B.x, A.y+B.y, A.z+B.z};
}

Vec3D operator - (Vec3D A, Vec3D B) {
    return (Vec3D) {A.x-B.x, A.y-B.y, A.z-B.z};
}

Vec3D operator * (Vec3D A, double B) {
    return (Vec3D) {A.x*B, A.y*B, A.z*B};
}

Vec3D operator / (Vec3D A, double B) {
    return (Vec3D) {A.x/B, A.y/B, A.z/B};
}