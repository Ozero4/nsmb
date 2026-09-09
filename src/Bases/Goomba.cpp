#include "Goomba.hpp"

Goomba::Goomba()
{
}

s32 Goomba::onCreate()
{
}

u32 Goomba::func_ov010_020e127c()
{
}

u32 Goomba::megaDroppedState()
{
    if (*(i8*)((u8*)this + 0x45A) == 0)
    {
        *(i8*)((u8*)this + 0x45A) += 1;

        *(i32*)((u8*)this + 0xBC) = -0x300;

        *(u32*)((u8*)this + 0xD0) = 0;
        *(u32*)((u8*)this + 0xD4) = 0;
        *(u32*)((u8*)this + 0xD8) = 0;
        *(u32*)((u8*)this + 0xE0) = 0;

        *(i32*)((u8*)this + 0xE4) = -0x8000;

        *(u32*)((u8*)this + 0xE8) = 0;

        *(u8*)((u8*)this + 0x458) = 0;
    }
    else if (*(i8*)((u8*)this + 0x45A) != -1)
    {
        *(i16*)((u8*)this + 0xA0) += 0x800;

        Actor::updateVerticalVelocity();

        this->StageEntity::func_ov000_0209c85c();

        if (func_020202a0() == 1)
        {
            this->func_ov010_020e19ac();
        }

        this->func_ov010_020e1694();
    }

    return 1;
}

extern u16 data_ov010_021217a0[2];

u32 Goomba::stompedState()
{
    u8* p = (u8*)this;

    if (*(i8*)(p + 0x45A) == 0) {
        *(u16*)(p + 0x440) = 1;
        *(u16*)(p + 0x442) = 0;
        *(u16*)(p + 0x444) = *data_ov010_021217a0;
        *(u16*)(p + 0x446) = 0;

        (*(i8*)(p + 0x45A))++;

        *(u16*)(p + 0x0A2) = 0;
        *(u16*)(p + 0x42C) = 0x1E;
        *(u8*)(p + 0x3E4) = 1;
        *(u16*)(p + 0x148) = 0;
    }
    else if (*(i8*)(p + 0x45A) != -1) {
        if (*(i16*)(p + 0x42C) == 0) {
            ((ActiveCollider*)(p + 0x120))->unlink();
            this->StageEntity::destroy(true);
        }
        else {
            *(i16*)(p + 0x42C) = *(i16*)(p + 0x42C) - 1;
        }

        this->func_ov010_020e1694();
    }

    return 1;
}

bool Goomba::onUpdate_defeated()
{
  *(i16*)((u8*)this + 0xA0) += 0x800;
  Actor::updateVerticalVelocity();
  this->Actor::applyVelocity();
  this->StageEntity::func_ov000_0209c820(-0x300);
  this->func_ov010_020e1694();
  this->StageEntity::destroyInactive(0);
  return true;
}

void Goomba::onStomped()
{
    *(u16 *)((i8*)this + 0x2c6) |= 0x0FF0;
    *(u16 *)((i8*)this + 0x148) &= -0x403;
    *(u16 *)((i8*)this + 0x14a) |= 0x8000;
}

bool Goomba::playerCollision(ActiveCollider* param_2, ActiveCollider* param_3)
{
    Actor* owner = param_3->owner;

    if (owner->actorType != 1)
        return false;

    if (*(u16*)((u8*)this + 0x452) != 0 &&
        *(i8*)((u8*)owner + 0x7AC) != 4)
    {
        if (*(u8*)((u8*)param_3 + 0x24) == 1)
        {
            if (this->StageEntity::func_ov000_0209d240())
                return true;
        }
        else
        {
            if (this->StageEntity::func_ov000_0209d3d0())
                return true;
        }
    }

    return this->StageEntity::playerCollision(param_2, param_3);
}

extern u32 data_02088b94[];

bool Goomba::updateMusicEvents(i32 param_2)
{
    if (*(i32*)((u8*)this + 0x428) != 0 &&
        *(i32*)(data_02088b94 + 2) > 0)
    {
        if (param_2 == 0x3000) {
            *(u32*)((u8*)this + 0xD4) = param_2;
            return true;
        }

        if ((*(u32*)((u8*)this + 0x24C) & 0x1f40) != 0) {
            *(u32*)((u8*)this + 0xD4) = param_2;
            this->_3ec = 3;
            return true;
        }
    }

    return false;
}

void *Goomba::create()
{
	return new Goomba();
}

void *ParaGoomba::create()
{
	return new ParaGoomba();
}

void *MiniGoomba::create()
{
	return new MiniGoomba();
}

ParaGoomba::~ParaGoomba()
{
}

MiniGoomba::~MiniGoomba()
{
}
