#pragma once
#include <map>
#include <vector>
#include <d3d11.h>
#include <XNAMath.h>
//#include <OVR.h>
#include <OVR_CAPI.h>
#include <OVR_CAPI_D3D.h>



class D3D11DeviceHooks : public ID3D11Device
{
public:
	D3D11DeviceHooks(ID3D11Device* inner, ovrHmd hmd);
private:

	// DirectX state tracking
	//ID3D11Device* parent;
	ID3D11Device* inner;
	ID3D11Texture2D* back_buffer_surface;
	//D3DPRESENT_PARAMETERS present_parameters;

	// OVR state tracking
	ovrHmd hmd;
	ovrTrackingState tracking_state;
	ovrEyeRenderDesc eye_render_desc[2];
	ovrPosef head_pose[2];

	// Render target helpers
	bool stereo;
	bool render_distorted;
	bool reset_pressed;
	unsigned int frame_index;
	ovrSizei target_size;
	ID3D11Texture1D* hmd_texture;

	// UI stereo rendering helpers
	struct stream_source_info {
		UINT number;
		ID3D11Buffer* data;
		UINT offset;
		UINT stride;
	} current_stream;
	struct ui_vertex {
		XMFLOAT4 position;
		DWORD color;
		XMFLOAT2 uv;
	};
	UINT stereo_quad_buffer_length;
	UINT stereo_quad_buffer_offset;
	ID3D11RenderTargetView* stereo_quad_buffer;

	// Scene stereo rendering helpers
	XMMATRIX model_matrix;
};

