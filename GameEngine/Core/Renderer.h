#pragma once

#include <iostream>
#include <windows.h>
#include <memory>
#include <vector>
#include <d3d11.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxgi.lib")

class Renderer
{
public:
	Renderer(HWND hWnd, const int& width, const int& height, const int& canvasWidth, const int& canvasHeight);
	~Renderer();

private:
	void InitRenderer(HWND hWnd, const int& width, const int& height, const int& canvasWidth, const int& canvasHeight);
	void Destrory();

	void CreateShaders();
	void Update();
	void Render();

private:

	ComPtr<ID3D11Device> device;
	ComPtr<ID3D11DeviceContext> devcon;
	ComPtr<IDXGISwapChain> swapchain;
	ComPtr<D3D11_VIEWPORT> viewport;
	ComPtr<ID3D11RenderTargetView> rtv;
	ComPtr<ID3D11VertexShader> vertexShdaer;
	ComPtr<ID3D11PixelShader> pixelShdaer;
	ComPtr<ID3D11InputLayout> layout;

	ComPtr<ID3D11Buffer> vertexBuffer;
	ComPtr<ID3D11Buffer> indexBuffer;
	ComPtr<ID3D11Texture2D> texture;
	ComPtr<ID3D11ShaderResourceView> textureView;
	ComPtr<ID3D11RenderTargetView> canvasRtv;
	ComPtr<ID3D11SamplerState> colorSampler;
	UINT indexCount;

	int width, height;
	float color[4] = { 0.0f, 0.2f, 0.8f, 1.0f };
};

