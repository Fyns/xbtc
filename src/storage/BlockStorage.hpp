#pragma once

#include <xul/lang/object.hpp>
#include <memory>


namespace xbtc {


class BlockIndex;
class BlockHeader;
class Block;
class AppInfo;
class BlockListener;
class DiskBlockPos;
class BlockIndexesData;

class BlockStorage : public xul::object
{
public:
    virtual bool load(BlockIndexesData& data) = 0;
    virtual DiskBlockPos writeBlock(Block* block, BlockIndex* blockIndex) = 0;
    virtual void flush(const std::shared_ptr<BlockIndexesData>& data) = 0;
};

BlockStorage* createBlockStorage(AppInfo* appInfo);

}