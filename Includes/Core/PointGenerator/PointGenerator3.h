/*************************************************************************
> File Name: PointGenerator3.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Abstract base class for 3-D point generator.
> Created Time: 2017/06/02
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_POINT_GENERATOR3_H
#define CUBBYFLOW_POINT_GENERATOR3_H

#include <Core/Array/Array1.h>
#include <Core/BoundingBox/BoundingBox3.h>

#include <functional>

namespace CubbyFlow
{
	//!
	//! \brief Abstract base class for 3-D point generator.
	//!
	//! This class provides interface for 3-D point generator. For given bounding
	//! box and point spacing, the inherited classes generates points with specified
	//! pattern.
	//!
	class PointGenerator3
	{
	public:
		PointGenerator3();

		virtual ~PointGenerator3();

		//! Generates points to output array \p points inside given \p boundingBox
		//! with target point \p spacing.
		void Generate(const BoundingBox3D& boundingBox, double spacing, Array1<Vector3D>* points) const;

		//!
		//! \brief Iterates every point within the bounding box with specified
		//! point pattern and invokes the callback function.
		//!
		//! This function iterates every point within the bounding box and invokes
		//! the callback function. The position of the point is specified by the
		//! actual implementation. The suggested spacing between the points are
		//! given by \p spacing. The input parameter of the callback function is
		//! the position of the point and the return value tells whether the
		//! iteration should stop or not.
		//!
		virtual void ForEachPoint(const BoundingBox3D& boundingBox, double spacing,
			const std::function<bool(const Vector3D&)>& callback) const = 0;
	};

	//! Shared pointer for the PointGenerator3 type.
	using PointGenerator3Ptr = std::shared_ptr<PointGenerator3>;
}

#endif