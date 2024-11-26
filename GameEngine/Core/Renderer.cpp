#include "Renderer.h"

Renderer::Renderer(HWND hWnd, const int& width, const int& height, const int& canvasWidth, const int& canvasHeight)
	:width(canvasWidth), height(canvasHeight)
{
	InitRenderer(hWnd, width, height, canvasWidth, canvasHeight);
}

Renderer::~Renderer()
{
}

void Renderer::InitRenderer(HWND hWnd, const int& width, const int& height, const int& canvasWidth, const int& canvasHeight)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferCount = 2;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
}

void Renderer::Destrory()
{
}

void Renderer::CreateShaders()
{
}

void Renderer::Update()
{
}

void Renderer::Render()
{
}
