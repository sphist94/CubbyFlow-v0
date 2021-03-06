/*************************************************************************
> File Name: VolumeGridEmitter.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: VolumeGridEmitter functions for CubbyFlow Python API.
> Created Time: 2018/02/11
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_PYTHON_VOLUME_GRID_EMITTER_H
#define CUBBYFLOW_PYTHON_VOLUME_GRID_EMITTER_H

#include <pybind11/pybind11.h>

void AddVolumeGridEmitter2(pybind11::module& m);
void AddVolumeGridEmitter3(pybind11::module& m);

#endif