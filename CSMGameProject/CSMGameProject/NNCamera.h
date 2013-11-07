
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
	NNPoint GetPosition() { return m_Position; }
	float GetPositionX() const { return m_Position.GetX(); }
	float GetPositionY() const { return m_Position.GetY(); }
	float GetRotation() const { return m_Rotation; }
	float GetZoom() const { return m_Zoom; }

	void SetCameraAnchor( CameraAnchor anchor );

private:
	CameraAnchor m_Anchor;

	NNPoint m_Position;
	float m_Rotation;
	float m_Zoom;
	int m_ScreenWidth;
	int m_ScreenHeight;
};