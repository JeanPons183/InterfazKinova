#ifndef GEN3LITE_H
#define GEN3LITE_H

#include <algorithm>
#include <cmath>

// Kinova Headers
#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>
#include <ActuatorConfigClientRpc.h>
#include <SessionClientRpc.h>
#include <SessionManager.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>
#include <TransportClientTcp.h>

// Mini matrices library
#include "mat.h"

namespace KinovaGen3litemodel
{

    // ----------- GEN3 lite --- GEAR RATIO AND TORQUE CONSTANTS ------------
    // GearRatio/TorqueConstant = Gr/Kt : LARGE actuator (A2)
    const float GroKt_large = 1 / (100 * 0.0398);
    // GearRatio/TorqueConstant = Gr/Kt : MEDIUM actuator (A1, A3)
    const float GroKt_medium = 1 / (30 * 0.0398);
    // GearRatio/TorqueConstant = Gr/Kt : SMALL actuator (A4, A5, A6)
    const float GroKt_small = 1 / (22 * 0.0251);
    mat<7, 1> KTGR = {GroKt_medium, GroKt_large, GroKt_medium, GroKt_small, GroKt_small, GroKt_small, 0}; //----------------------------------------------------------------------

    // ----------- GEN 3 LITE GRAVITY VECTOR EXPRESSION ----------------------------------------
    mat<7, 1> GravityVector(const mat<7, 1> &q)
    {
        mat<7, 1> g = {};

        float m2 = 1.1776;
        float m3 = 0.59768;
        float m4 = 0.52693;
        float m5 = 0.58097;
        float m6 = 0.2018;
        // Precalculate sin(q) and cos(q)
        double s1 = sin(q[0][0]);
        double s2 = sin(q[1][0]);
        double s3 = sin(q[2][0]);
        double s4 = sin(q[3][0]);
        double s5 = sin(q[4][0]);
        double s6 = sin(q[5][0]);
        double c1 = cos(q[0][0]);
        double c2 = cos(q[1][0]);
        double c3 = cos(q[2][0]);
        double c4 = cos(q[3][0]);
        double c5 = cos(q[4][0]);
        double c6 = cos(q[5][0]);

        g[0][0] = 0;
        g[1][0] = (49 * m6 * ((199 * c6 * (s5 * (c2 * s3 - c3 * s2) - c5 * s4 * (c2 * c3 + s2 * s3))) / 20000 - (7 * s2) / 25 + (49 * c2 * s3) / 200 - (49 * c3 * s2) / 200 + (993 * s6 * (s5 * (c2 * s3 - c3 * s2) - c5 * s4 * (c2 * c3 + s2 * s3))) / 100000 + (57 * c4 * (c2 * c3 + s2 * s3)) / 1000 + (4159 * c5 * (c2 * s3 - c3 * s2)) / 25000 + (993 * c4 * c6 * (c2 * c3 + s2 * s3)) / 100000 - (199 * c4 * s6 * (c2 * c3 + s2 * s3)) / 20000 + (4159 * s4 * s5 * (c2 * c3 + s2 * s3)) / 25000)) / 5 - (49 * m4 * ((7 * s2) / 25 - (409272722616623101 * c2 * s3) / 1801439850948198400 + (409272722616623101 * c3 * s2) / 1801439850948198400 - (828950561812323 * c4 * (c2 * c3 + s2 * s3)) / 144115188075855872 + (5766913366043449 * s4 * (c2 * c3 + s2 * s3)) / 576460752303423488)) / 5 + (49 * m2 * ((8642011368156773 * c2) / 288230376151711744 - (4231 * s2) / 20000)) / 5 + (49 * m5 * ((49 * c2 * s3) / 200 - (7 * s2) / 25 - (49 * c3 * s2) / 200 + (850784012805815169 * c4 * (c2 * c3 + s2 * s3)) / 18014398509481984000 + (11338515749347 * c5 * (c2 * s3 - c3 * s2)) / 140737488355328 + (1412905303895691 * s5 * (c2 * s3 - c3 * s2)) / 144115188075855872 - (1412905303895691 * c5 * s4 * (c2 * c3 + s2 * s3)) / 144115188075855872 + (11338515749347 * s4 * s5 * (c2 * c3 + s2 * s3)) / 140737488355328)) / 5 + (49 * m3 * ((8691875223231019 * c2 * c3) / 288230376151711744 - (7 * s2) / 25 + (1711764175167997 * c2 * s3) / 18014398509481984 - (1711764175167997 * c3 * s2) / 18014398509481984 + (8691875223231019 * s2 * s3) / 288230376151711744)) / 5;
        g[2][0] = -(49 * m6 * ((199 * c6 * (s5 * (c2 * s3 - c3 * s2) - c5 * s4 * (c2 * c3 + s2 * s3))) / 20000 + (49 * c2 * s3) / 200 - (49 * c3 * s2) / 200 + (993 * s6 * (s5 * (c2 * s3 - c3 * s2) - c5 * s4 * (c2 * c3 + s2 * s3))) / 100000 + (57 * c4 * (c2 * c3 + s2 * s3)) / 1000 + (4159 * c5 * (c2 * s3 - c3 * s2)) / 25000 + (993 * c4 * c6 * (c2 * c3 + s2 * s3)) / 100000 - (199 * c4 * s6 * (c2 * c3 + s2 * s3)) / 20000 + (4159 * s4 * s5 * (c2 * c3 + s2 * s3)) / 25000)) / 5 - (49 * m4 * ((409272722616623101 * c2 * s3) / 1801439850948198400 - (409272722616623101 * c3 * s2) / 1801439850948198400 + (828950561812323 * c4 * (c2 * c3 + s2 * s3)) / 144115188075855872 - (5766913366043449 * s4 * (c2 * c3 + s2 * s3)) / 576460752303423488)) / 5 - (49 * m5 * ((49 * c2 * s3) / 200 - (49 * c3 * s2) / 200 + (850784012805815169 * c4 * (c2 * c3 + s2 * s3)) / 18014398509481984000 + (11338515749347 * c5 * (c2 * s3 - c3 * s2)) / 140737488355328 + (1412905303895691 * s5 * (c2 * s3 - c3 * s2)) / 144115188075855872 - (1412905303895691 * c5 * s4 * (c2 * c3 + s2 * s3)) / 144115188075855872 + (11338515749347 * s4 * s5 * (c2 * c3 + s2 * s3)) / 140737488355328)) / 5 - (49 * m3 * ((8691875223231019 * c2 * c3) / 288230376151711744 + (1711764175167997 * c2 * s3) / 18014398509481984 - (1711764175167997 * c3 * s2) / 18014398509481984 + (8691875223231019 * s2 * s3) / 288230376151711744)) / 5;
        g[2][0] *= 1.1;
        g[3][0] = (49 * m4 * ((5766913366043449 * c4 * (c2 * s3 - c3 * s2)) / 576460752303423488 + (828950561812323 * s4 * (c2 * s3 - c3 * s2)) / 144115188075855872)) / 5 + (49 * m5 * ((850784012805815169 * s4 * (c2 * s3 - c3 * s2)) / 18014398509481984000 + (1412905303895691 * c4 * c5 * (c2 * s3 - c3 * s2)) / 144115188075855872 - (11338515749347 * c4 * s5 * (c2 * s3 - c3 * s2)) / 140737488355328)) / 5 + (49 * m6 * ((57 * s4 * (c2 * s3 - c3 * s2)) / 1000 - (4159 * c4 * s5 * (c2 * s3 - c3 * s2)) / 25000 + (993 * c6 * s4 * (c2 * s3 - c3 * s2)) / 100000 - (199 * s4 * s6 * (c2 * s3 - c3 * s2)) / 20000 + (199 * c4 * c5 * c6 * (c2 * s3 - c3 * s2)) / 20000 + (993 * c4 * c5 * s6 * (c2 * s3 - c3 * s2)) / 100000)) / 5;
        g[4][0] = (49 * m6 * ((199 * c6 * (c5 * (c2 * c3 + s2 * s3) - s4 * s5 * (c2 * s3 - c3 * s2))) / 20000 + (993 * s6 * (c5 * (c2 * c3 + s2 * s3) - s4 * s5 * (c2 * s3 - c3 * s2))) / 100000 - (4159 * s5 * (c2 * c3 + s2 * s3)) / 25000 - (4159 * c5 * s4 * (c2 * s3 - c3 * s2)) / 25000)) / 5 - (49 * m5 * ((11338515749347 * s5 * (c2 * c3 + s2 * s3)) / 140737488355328 - (1412905303895691 * c5 * (c2 * c3 + s2 * s3)) / 144115188075855872 + (11338515749347 * c5 * s4 * (c2 * s3 - c3 * s2)) / 140737488355328 + (1412905303895691 * s4 * s5 * (c2 * s3 - c3 * s2)) / 144115188075855872)) / 5;
        g[5][0] = (49 * m6 * ((993 * c6 * (s5 * (c2 * c3 + s2 * s3) + c5 * s4 * (c2 * s3 - c3 * s2))) / 100000 - (199 * s6 * (s5 * (c2 * c3 + s2 * s3) + c5 * s4 * (c2 * s3 - c3 * s2))) / 20000 + (199 * c4 * c6 * (c2 * s3 - c3 * s2)) / 20000 + (993 * c4 * s6 * (c2 * s3 - c3 * s2)) / 100000)) / 5;
        return g;
    }

    // ----------- * GEN 3 * POSE ----------------------------------------------------------------
    mat<7, 1> GetPose(const mat<7, 1> &q, const mat<7, 1> &lastPose = zeros<7, 1>())
    {
        mat<7, 1> pose;

        // Precalculate sin(q) and cos(q)
        double s1 = sin(q[0][0]);
        double s2 = sin(q[1][0]);
        double s3 = sin(q[2][0]);
        double s4 = sin(q[3][0]);
        double s5 = sin(q[4][0]);
        double s6 = sin(q[5][0]);
        double c1 = cos(q[0][0]);
        double c2 = cos(q[1][0]);
        double c3 = cos(q[2][0]);
        double c4 = cos(q[3][0]);
        double c5 = cos(q[4][0]);
        double c6 = cos(q[5][0]);

        // Direct Kinematics
        mat<4, 4> T;
        T[0][0] = - c6*(s1*s4 - c4*(c1*c2*c3 + c1*s2*s3)) - s6*(c5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)) - s5*(c1*c2*s3 - c1*c3*s2));
        T[0][1] = s6*(s1*s4 - c4*(c1*c2*c3 + c1*s2*s3)) - c6*(c5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)) - s5*(c1*c2*s3 - c1*c3*s2));
        T[0][2] = s5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)) + c5*(c1*c2*s3 - c1*c3*s2);
        T[0][3] = s1/100 - (7*c1*s2)/25 - (57*s1*s4)/1000 + (47*s5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)))/200 + (57*c4*(c1*c2*c3 + c1*s2*s3))/1000 + (47*c5*(c1*c2*s3 - c1*c3*s2))/200 + (49*c1*c2*s3)/200 - (49*c1*c3*s2)/200;
        T[1][0] = c6*(c1*s4 + c4*(s1*s2*s3 + c2*c3*s1)) + s6*(c5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1)) + s5*(c2*s1*s3 - c3*s1*s2)); 
        T[1][1] = c6*(c5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1)) + s5*(c2*s1*s3 - c3*s1*s2)) - s6*(c1*s4 + c4*(s1*s2*s3 + c2*c3*s1));
        T[1][2] = c5*(c2*s1*s3 - c3*s1*s2) - s5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1));
        T[1][3] = (57*c1*s4)/1000 - c1/100 - (7*s1*s2)/25 - (47*s5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1)))/200 + (57*c4*(s1*s2*s3 + c2*c3*s1))/1000 + (47*c5*(c2*s1*s3 - c3*s1*s2))/200 + (49*c2*s1*s3)/200 - (49*c3*s1*s2)/200;
        T[2][0] = s6*(s5*(c2*c3 + s2*s3) + c5*s4*(c2*s3 - c3*s2)) - c4*c6*(c2*s3 - c3*s2);
        T[2][1] = c6*(s5*(c2*c3 + s2*s3) + c5*s4*(c2*s3 - c3*s2)) + c4*s6*(c2*s3 - c3*s2);
        T[2][2] = c5*(c2*c3 + s2*s3) - s4*s5*(c2*s3 - c3*s2);
        T[2][3] = (7*c2)/25 + (49*c2*c3)/200 + (49*s2*s3)/200 - (57*c4*(c2*s3 - c3*s2))/1000 + (47*c5*(c2*c3 + s2*s3))/200 - (47*s4*s5*(c2*s3 - c3*s2))/200 + 2433/10000;
        T[3][0] = 0;
        T[3][1] = 0;
        T[3][2] = 0;
        T[3][3] = 1;

        // Unit Quaternion obtentionloat* q algorithm
        // Richard A. Spurrier 1978
        // Trace of Direct Kinematics Rotation Matrix
        double r_trace = trace(select<0, 3, 0, 3>(T));
        double w = r_trace;
        double x = 0;
        double y = 0;
        double z = 0;
        // if(trace > 0) w = 0;
        double i = std::max({T[0][0], T[1][1], T[2][2], w});
        if (i == w)
        {
            w = sqrt(r_trace + 1) / 2;
            x = (T[2][1] - T[1][2]) / (4 * w);
            y = (T[0][2] - T[2][0]) / (4 * w);
            z = (T[1][0] - T[0][1]) / (4 * w);
        }
        if (i == T[0][0])
        {
            x = sqrt((T[0][0] / 2) + ((1 - r_trace) / 4));
            w = (T[2][1] - T[1][2]) / (4 * x);
            y = (T[1][0] + T[0][1]) / (4 * x);
            z = (T[2][0] + T[0][2]) / (4 * x);
        }
        if (i == T[1][1])
        {
            y = sqrt((T[1][1] / 2) + ((1 - r_trace) / 4));
            w = (T[0][2] - T[2][0]) / (4 * y);
            z = (T[2][1] + T[1][2]) / (4 * y);
            x = (T[0][1] + T[1][0]) / (4 * y);
        }
        if (i == T[2][2])
        {
            z = sqrt((T[2][2] / 2) + ((1 - r_trace) / 4));
            w = (T[1][0] - T[0][1]) / (4 * z);
            x = (T[0][2] + T[2][0]) / (4 * z);
            y = (T[1][2] + T[2][1]) / (4 * z);
        }

        pose[0][0] = T[0][3]; // x
        pose[1][0] = T[1][3]; // y
        pose[2][0] = T[2][3]; // z
        pose[3][0] = w;       // eta
        pose[4][0] = x;       // beta_1
        pose[5][0] = y;       // beta_2
        pose[6][0] = z;       // beta_3

        if (lastPose[0][0] != 0 && lastPose[1][0] != 0 && lastPose[2][0] != 0 && lastPose[3][0] != 0 && lastPose[4][0] != 0 && lastPose[5][0] != 0 && lastPose[6][0] != 0)
        {
            auto innerProd = trans(lastPose) * pose;
            if (innerProd[0][0] < 0)
            {
                for (unsigned int i = 3; i < 7; i++)
                {
                    pose[i][0] = -pose[i][0];
                }
            }
        }
        return pose;
    }
    // ----------- * GEN 3 * JACOBIAN ----------------------------------------------------------------
    mat<6, 7> GetJacobian(const mat<7, 1> &q)
    {
        // 6 rows , 7 colums
        mat<6, 7> jacobian = {};
        // Precalculate sin(q) and cos(q)
        double s1 = sin(q[0][0]);
        double s2 = sin(q[1][0]);
        double s3 = sin(q[2][0]);
        double s4 = sin(q[3][0]);
        double s5 = sin(q[4][0]);
        double s6 = sin(q[5][0]);
        double c1 = cos(q[0][0]);
        double c2 = cos(q[1][0]);
        double c3 = cos(q[2][0]);
        double c4 = cos(q[3][0]);
        double c5 = cos(q[4][0]);
        double c6 = cos(q[5][0]);

        // 1st row
        jacobian[0][0] = c1/100 - (57*c1*s4)/1000 + (7*s1*s2)/25 + (47*s5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1)))/200 - (57*c4*(s1*s2*s3 + c2*c3*s1))/1000 - (47*c5*(c2*s1*s3 - c3*s1*s2))/200 - (49*c2*s1*s3)/200 + (49*c3*s1*s2)/200;
        jacobian[0][1] = (57*c4*(c1*c2*s3 - c1*c3*s2))/1000 - (7*c1*c2)/25 - (47*c5*(c1*c2*c3 + c1*s2*s3))/200 + (47*s4*s5*(c1*c2*s3 - c1*c3*s2))/200 - (49*c1*c2*c3)/200 - (49*c1*s2*s3)/200;
        jacobian[0][2] = (47*c5*(c1*c2*c3 + c1*s2*s3))/200 - (57*c4*(c1*c2*s3 - c1*c3*s2))/1000 - (47*s4*s5*(c1*c2*s3 - c1*c3*s2))/200 + (49*c1*c2*c3)/200 + (49*c1*s2*s3)/200;
        jacobian[0][3] = - (57*c4*s1)/1000 - (47*s5*(s1*s4 - c4*(c1*c2*c3 + c1*s2*s3)))/200 - (57*s4*(c1*c2*c3 + c1*s2*s3))/1000;
        jacobian[0][4] = (47*c5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)))/200 - (47*s5*(c1*c2*s3 - c1*c3*s2))/200;
        jacobian[0][5] = 0;

        // 2nd row
        jacobian[1][0] = s1/100 - (7*c1*s2)/25 - (57*s1*s4)/1000 + (47*s5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)))/200 + (57*c4*(c1*c2*c3 + c1*s2*s3))/1000 + (47*c5*(c1*c2*s3 - c1*c3*s2))/200 + (49*c1*c2*s3)/200 - (49*c1*c3*s2)/200;
        jacobian[1][1] = (57*c4*(c2*s1*s3 - c3*s1*s2))/1000 - (7*c2*s1)/25 - (47*c5*(s1*s2*s3 + c2*c3*s1))/200 - (49*s1*s2*s3)/200 + (47*s4*s5*(c2*s1*s3 - c3*s1*s2))/200 - (49*c2*c3*s1)/200;
        jacobian[1][2] = (47*c5*(s1*s2*s3 + c2*c3*s1))/200 - (57*c4*(c2*s1*s3 - c3*s1*s2))/1000 + (49*s1*s2*s3)/200 - (47*s4*s5*(c2*s1*s3 - c3*s1*s2))/200 + (49*c2*c3*s1)/200;
        jacobian[1][3] = (57*c1*c4)/1000 + (47*s5*(c1*s4 + c4*(s1*s2*s3 + c2*c3*s1)))/200 - (57*s4*(s1*s2*s3 + c2*c3*s1))/1000;
        jacobian[1][4] = - (47*c5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1)))/200 - (47*s5*(c2*s1*s3 - c3*s1*s2))/200;
        jacobian[1][5] = 0;

        // 3rd row
        jacobian[2][0] = 0;
        jacobian[2][1] = (49*c2*s3)/200 - (7*s2)/25 - (49*c3*s2)/200 + (57*c4*(c2*c3 + s2*s3))/1000 + (47*c5*(c2*s3 - c3*s2))/200 + (47*s4*s5*(c2*c3 + s2*s3))/200;
        jacobian[2][2] = (49*c3*s2)/200 - (49*c2*s3)/200 - (57*c4*(c2*c3 + s2*s3))/1000 - (47*c5*(c2*s3 - c3*s2))/200 - (47*s4*s5*(c2*c3 + s2*s3))/200;
        jacobian[2][3] = (57*s4*(c2*s3 - c3*s2))/1000 - (47*c4*s5*(c2*s3 - c3*s2))/200;
        jacobian[2][4] = - (47*s5*(c2*c3 + s2*s3))/200 - (47*c5*s4*(c2*s3 - c3*s2))/200;
        jacobian[2][5] = 0;

        // 4th row
        jacobian[3][0] = 0;
        jacobian[3][1] = s1;
        jacobian[3][2] = -s1;
        jacobian[3][3] = c1*c2*s3 - c1*c3*s2;
        jacobian[3][4] = c4*(c1*c2*c3 + c1*s2*s3) - s1*s4;
        jacobian[3][5] = s5*(c4*s1 + s4*(c1*c2*c3 + c1*s2*s3)) + c5*(c1*c2*s3 - c1*c3*s2);

        // 5th row
        jacobian[4][0] = 0;
        jacobian[4][1] = -c1;
        jacobian[4][2] = c1;
        jacobian[4][3] = c2*s1*s3 - c3*s1*s2;
        jacobian[4][4] = c1*s4 + c4*(s1*s2*s3 + c2*c3*s1);
        jacobian[4][5] = c5*(c2*s1*s3 - c3*s1*s2) - s5*(c1*c4 - s4*(s1*s2*s3 + c2*c3*s1));

        // 6th row
        jacobian[5][0] = 1;
        jacobian[5][1] = 0;
        jacobian[5][2] = 0;
        jacobian[5][3] =  c2*c3 + s2*s3;
        jacobian[5][4] = -c4*(c2*s3 - c3*s2);
        jacobian[5][5] = c5*(c2*c3 + s2*s3) - s4*s5*(c2*s3 - c3*s2);

        return jacobian;
    }
    
    // Set actuators in POSITION (1) or CURRENT (0) control mode
    // -- 'actuators' acts as a selector of WHICH actuators are set on CURRENT (0), POSITION (1) or VELOCITY (2)  control mode
    // -- For consistency, the last 'actuator' data is ignored. 
    void ControlMode(Kinova::Api::ActuatorConfig::ActuatorConfigClient *actuator_config, array<int, 7> actuators = {1, 1, 1, 1, 1, 1, 1})
    {
        auto control_mode_message = Kinova::Api::ActuatorConfig::ControlModeInformation();
        for (int i = 0; i < 5; i++)
        {	
            switch(actuators[i]){
            case 0 :
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::CURRENT);
                break; 
            case 2: 
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::VELOCITY);
                break;
            default :
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::POSITION);            
            }
            actuator_config->SetControlMode(control_mode_message, i + 1);
        }
        // Special CASE:
        // -- 6th joint on the Kinova Gen 3 lite is referred to as the 7th joint
        // -- idk why. It's just an error that we can only work around
        switch(actuators[5]){
            case 0 :
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::CURRENT);
                break; 
            case 2: 
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::VELOCITY);
                break;
            default :
                control_mode_message.set_control_mode(Kinova::Api::ActuatorConfig::ControlMode::POSITION);            
            }
            actuator_config->SetControlMode(control_mode_message, 7);
    }

}
#endif
