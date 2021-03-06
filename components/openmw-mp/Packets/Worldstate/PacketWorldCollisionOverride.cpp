#include "PacketWorldCollisionOverride.hpp"
#include <components/openmw-mp/NetworkMessages.hpp>

using namespace mwmp;

PacketWorldCollisionOverride::PacketWorldCollisionOverride(RakNet::RakPeerInterface *peer) : WorldstatePacket(peer)
{
    packetID = ID_WORLD_COLLISION_OVERRIDE;
    orderChannel = CHANNEL_WORLDSTATE;
}

void PacketWorldCollisionOverride::Packet(RakNet::BitStream *bs, bool send)
{
    WorldstatePacket::Packet(bs, send);

    RW(worldstate->hasPlayerCollision, send);
    RW(worldstate->hasActorCollision, send);
    RW(worldstate->hasPlacedObjectCollision, send);
    RW(worldstate->useActorCollisionForPlacedObjects, send);
}
