#pragma once
#include <array>

struct HolonomicVector3 {

    /** @brief X axial direction on a flat 2D surface
     *  @note Can be thought of as "left and right" or "strafe" more generally
    */
    long X;

    /** @brief Y axial direction on a flat 2D surface
     *  @note Can be thought of as "fwd and back"
    */
    long Y;

    /** @brief W axial direction, or rotation of the frame.
     *  @note Represents the rotation about Z in a 3D frame of reference
    */
    long W;

};

class OmniDrive_Tri {

    public:
        static const unsigned char NUM_WHEELS = 3;

        std::array<long, NUM_WHEELS> getOutputs(long const& input_x, long const& input_y, long const& input_w);

    protected:

        HolonomicVector3 m_axial_magnitudes;
        
        std::array<float, NUM_WHEELS> m_gains;

        double m_drive_angle;

};  