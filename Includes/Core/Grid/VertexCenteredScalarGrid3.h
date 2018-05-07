/*************************************************************************
> File Name: VertexCenteredScalarGrid3.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: 3-D Vertex-centered scalar grid structure.
> Created Time: 2017/07/08
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_VERTEX_CENTERED_SCALAR_GRID3_H
#define CUBBYFLOW_VERTEX_CENTERED_SCALAR_GRID3_H

#include <Core/Grid/ScalarGrid3.h>

namespace CubbyFlow
{
	//!
	//! \brief 3-D Vertex-centered scalar grid structure.
	//!
	//! This class represents 3-D vertex-centered scalar grid which extends
	//! ScalarGrid3. As its name suggests, the class defines the data point at the
	//! grid vertices (corners). Thus, A x B x C grid resolution will have
	//! (A+1) x (B+1) x (C+1) data points.
	//!
	class VertexCenteredScalarGrid3 final : public ScalarGrid3
	{
	public:
		CUBBYFLOW_GRID3_TYPE_NAME(VertexCenteredScalarGrid3)

		class Builder;

		//! Constructs zero-sized grid.
		VertexCenteredScalarGrid3();

		//! Constructs a grid with given resolution, grid spacing, origin and
		//! initial value.
		VertexCenteredScalarGrid3(
			size_t resolutionX, size_t resolutionY, size_t resolutionZ,
			double gridSpacingX = 1.0, double gridSpacingY = 1.0, double gridSpacingZ = 1.0,
			double originX = 0.0, double originY = 0.0, double originZ = 0.0,
			double initialValue = 0.0);

		//! Constructs a grid with given resolution, grid spacing, origin and
		//! initial value.
		VertexCenteredScalarGrid3(
			const Size3& resolution,
			const Vector3D& gridSpacing = Vector3D(1.0, 1.0, 1.0),
			const Vector3D& origin = Vector3D(),
			double initialValue = 0.0);

		//! Copy constructor.
		VertexCenteredScalarGrid3(const VertexCenteredScalarGrid3& other);

		//! Returns the actual data point size.
		Size3 GetDataSize() const override;

		//! Returns data position for the grid point at (0, 0, 0).
		//! Note that this is different from origin() since origin() returns
		//! the lower corner point of the bounding box.
		Vector3D GetDataOrigin() const override;

		//! Returns the copy of the grid instance.
		std::shared_ptr<ScalarGrid3> Clone() const override;

		//!
		//! \brief Swaps the contents with the given \p other grid.
		//!
		//! This function swaps the contents of the grid instance with the given
		//! grid object \p other only if \p other has the same type with this grid.
		//!
		void Swap(Grid3* other) override;

		//! Sets the contents with the given \p other grid.
		void Set(const VertexCenteredScalarGrid3& other);

		//! Sets the contents with the given \p other grid.
		VertexCenteredScalarGrid3& operator=(const VertexCenteredScalarGrid3& other);

		//! Returns builder fox VertexCenteredScalarGrid3.
		static Builder GetBuilder();
	};

	//! Shared pointer for the VertexCenteredScalarGrid3 type.
	using VertexCenteredScalarGrid3Ptr = std::shared_ptr<VertexCenteredScalarGrid3>;

	//! A grid builder class that returns 3-D vertex-centered scalar grid.
	class VertexCenteredScalarGrid3::Builder final : public ScalarGridBuilder3
	{
	public:
		//! Returns builder with resolution.
		Builder& WithResolution(const Size3& resolution);

		//! Returns builder with resolution.
		Builder& WithResolution(size_t resolutionX, size_t resolutionY, size_t resolutionZ);

		//! Returns builder with grid spacing.
		Builder& WithGridSpacing(const Vector3D& gridSpacing);

		//! Returns builder with grid spacing.
		Builder& WithGridSpacing(double gridSpacingX, double gridSpacingY, double gridSpacingZ);

		//! Returns builder with grid origin.
		Builder& WithOrigin(const Vector3D& gridOrigin);

		//! Returns builder with grid origin.
		Builder& WithOrigin(double gridOriginX, double gridOriginY, double gridOriginZ);

		//! Returns builder with initial value.
		Builder& WithInitialValue(double initialVal);

		//! Builds VertexCenteredScalarGrid3 instance.
		VertexCenteredScalarGrid3 Build() const;

		//! Builds shared pointer of VertexCenteredScalarGrid3 instance.
		VertexCenteredScalarGrid3Ptr MakeShared() const;

		//!
		//! \brief Builds shared pointer of VertexCenteredScalarGrid3 instance.
		//!
		//! This is an overriding function that implements ScalarGridBuilder3.
		//!
		ScalarGrid3Ptr Build(
			const Size3& resolution,
			const Vector3D& gridSpacing,
			const Vector3D& gridOrigin,
			double initialVal) const override;

	private:
		Size3 m_resolution{ 1, 1, 1 };
		Vector3D m_gridSpacing{ 1, 1, 1 };
		Vector3D m_gridOrigin{ 0, 0, 0 };
		double m_initialVal = 0.0;
	};
}

#endif