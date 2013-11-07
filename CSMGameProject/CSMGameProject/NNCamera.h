
#pragma once

#include "NNPoint.h"

enum CameraAnchor
{
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	MIDDLE_LEFT,
	MIDDLE_CENTER,
	MIDDLE_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT,
	CUSTOM,
};

class NNCamera
{
public:
	NNCamera();
	~NNCamera();

	CameraAnchor GetAnchorStatus() const { return m_Anchor; }
	void SetCameraAnchor( CameraAnchor anchor );

private:
	CameraAnchor m_Anchor;

	NNPoint m_Position;
	float m_Rotation;
};