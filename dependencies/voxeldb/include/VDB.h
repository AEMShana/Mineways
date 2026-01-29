#pragma once
#include <cstdint>

namespace vdb {
    class SparseVoxelChunk;
}

extern "C" __declspec(dllexport)
void VDB__Init();

extern "C" __declspec(dllexport)
vdb::SparseVoxelChunk* NativeSparseVoxelChunk__Create();

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Destroy(vdb::SparseVoxelChunk* chunk);

extern "C" __declspec(dllexport)
uint16_t NativeSparseVoxelChunk__GetVoxel(vdb::SparseVoxelChunk* chunk, uint32_t x, uint32_t y, uint32_t z);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SetVoxel(vdb::SparseVoxelChunk* chunk, uint32_t x, uint32_t y, uint32_t z, uint16_t value);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SetRegion(vdb::SparseVoxelChunk* chunk, uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, uint32_t z1, uint32_t z2, uint16_t value);

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsEmpty(vdb::SparseVoxelChunk* chunk);

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsRegionEmpty(vdb::SparseVoxelChunk* chunk, uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, uint32_t z1, uint32_t z2);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Fill(vdb::SparseVoxelChunk* chunk, uint16_t value);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Clear(vdb::SparseVoxelChunk* chunk);

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsBlockEmpty(vdb::SparseVoxelChunk* chunk, uint32_t bx, uint32_t by, uint32_t bz);

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsBlockUniform(vdb::SparseVoxelChunk* chunk, uint32_t bx, uint32_t by, uint32_t bz, uint16_t* value);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__LoadFromVoxelFile(vdb::SparseVoxelChunk* chunk, const char* path);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SaveToVoxelFile(vdb::SparseVoxelChunk* chunk, const char* path);

extern "C" __declspec(dllexport)
uint32_t NativeSparseVoxelChunk__GenerateMesh(vdb::SparseVoxelChunk* chunk);

extern "C" __declspec(dllexport)
uint32_t NativeSparseVoxelChunk__GenerateSubChunkMesh(vdb::SparseVoxelChunk* chunk, int offset_x, int offset_y, int offset_z);

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__CopyMesh(vdb::SparseVoxelChunk* chunk, void* data);