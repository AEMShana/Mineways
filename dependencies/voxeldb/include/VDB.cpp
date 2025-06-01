#include "VDB.h"
#include "SparseVoxelChunk.h"
#include "LogSystem.h"

__declspec(dllexport) extern "C"
void VDB__Init() {
    vdb::LogSystem::Init();
}

__declspec(dllexport)
vdb::SparseVoxelChunk* NativeSparseVoxelChunk__Create() {
    return new vdb::SparseVoxelChunk();
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Destroy(vdb::SparseVoxelChunk* chunk) {
    delete chunk;
}

extern "C" __declspec(dllexport)
uint32_t NativeSparseVoxelChunk__GetVoxel(vdb::SparseVoxelChunk* chunk, uint32_t x, uint32_t y, uint32_t z) {
    return chunk->GetVoxel(x, y, z);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SetVoxel(vdb::SparseVoxelChunk* chunk, uint32_t x, uint32_t y, uint32_t z, uint32_t value) {
    chunk->SetVoxel(x, y, z, value);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SetVoxelColor(vdb::SparseVoxelChunk* chunk, uint32_t x, uint32_t y, uint32_t z, uint32_t r, uint32_t g, uint32_t b) {
    chunk->SetVoxel(x, y, z, r, g, b);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SetRegion(vdb::SparseVoxelChunk* chunk, uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, uint32_t z1, uint32_t z2, uint32_t value) {
    chunk->SetRegion(x1, x2, y1, y2, z1, z2, value);
}

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsEmpty(vdb::SparseVoxelChunk* chunk) {
    return chunk->IsEmpty();
}

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsRegionEmpty(vdb::SparseVoxelChunk* chunk, uint32_t x1, uint32_t x2, uint32_t y1, uint32_t y2, uint32_t z1, uint32_t z2) {
    return chunk->IsRegionEmpty(x1, x2, y1, y2, z1, z2);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Fill(vdb::SparseVoxelChunk* chunk, uint32_t value) {
    chunk->Fill(value);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__Clear(vdb::SparseVoxelChunk* chunk) {
    chunk->Clear();
}

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsBlockEmpty(vdb::SparseVoxelChunk* chunk, uint32_t bx, uint32_t by, uint32_t bz) {
    return chunk->IsBlockEmpty(bx, by, bz);
}

extern "C" __declspec(dllexport)
bool NativeSparseVoxelChunk__IsBlockUniform(vdb::SparseVoxelChunk* chunk, uint32_t bx, uint32_t by, uint32_t bz, uint32_t* value) {
    return chunk->IsBlockUniform(bx, by, bz, *value);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__LoadFromVoxelFile(vdb::SparseVoxelChunk* chunk, const char* path) {
    chunk->LoadFromVoxelFile(path);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__SaveToVoxelFile(vdb::SparseVoxelChunk* chunk, const char* path) {
    chunk->SaveToVoxelFile(path);
}

extern "C" __declspec(dllexport)
uint32_t NativeSparseVoxelChunk__GenerateMesh(vdb::SparseVoxelChunk* chunk) {
    return vdb::g_mesh_generator.GenerateMesh(*chunk);
}

extern "C" __declspec(dllexport)
uint32_t NativeSparseVoxelChunk__GenerateSubChunkMesh(vdb::SparseVoxelChunk* chunk, int offset_x, int offset_y, int offset_z) {
    return vdb::g_mesh_generator.GenerateSubChunkMesh(*chunk, offset_x, offset_y, offset_z);
}

extern "C" __declspec(dllexport)
void NativeSparseVoxelChunk__CopyMesh(vdb::SparseVoxelChunk* chunk, void* data) {
    return vdb::g_mesh_generator.CopyMesh(data);
}