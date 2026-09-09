#pragma once
#include "StageEntity.hpp"

class Goomba : public StageEntity
{
public:
	u8 _pad0[0x68];

	static void *create();
	inline Goomba();

    u32 func_ov010_020e127c();
    u32 megaDroppedState();
    u32 stompedState();
    bool onUpdate_defeated();
    bool func_ov010_020e1694();
    void func_ov010_020e19ac();
    void onStomped();
    bool playerCollision(ActiveCollider* param_2, ActiveCollider* param_3);
    bool updateMusicEvents(s32 param_2);

	s32 onCreate();
};

class ParaGoomba : public Goomba
{
public:

    static void *create();
    ~ParaGoomba();
};

class MiniGoomba : public Goomba
{
public:

    static void *create();
        ~MiniGoomba();

};
