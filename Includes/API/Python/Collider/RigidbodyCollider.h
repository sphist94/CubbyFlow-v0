/*************************************************************************
> File Name: RigidbodyCollider.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: RigidbodyCollider functions for CubbyFlow Python API.
> Created Time: 2018/02/10
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_PYTHON_RIGIDBODY_COLLIDER_H
#define CUBBYFLOW_PYTHON_RIGIDBODY_COLLIDER_H

#include <pybind11/pybind11.h>

void AddRigidBodyCollider2(pybind11::module& m);
void AddRigidBodyCollider3(pybind11::module& m);

#endif