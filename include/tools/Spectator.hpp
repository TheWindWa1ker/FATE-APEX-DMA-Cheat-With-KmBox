#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "game/Player.hpp"
#include "game/LocalPlayer.hpp"


//struct Spectator {
//    // Variables
//    LocalPlayer* Myself;
//    std::vector<Player*>* Players;
//    float spec_glow = 0;
//    int TotalSpectators = 0;
//    std::vector<std::string> Spectators;
//    std::chrono::milliseconds LastUpdateTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
//
//    Spectator(std::vector<Player*>* Players, LocalPlayer* Myself) {
//        this->Players = Players;
//        this->Myself = Myself;
//    }
//
//    void Update() {
//        std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
//        if (Now >= LastUpdateTime + std::chrono::milliseconds(1500))
//        {
//            int TempTotalSpectators = 0;
//            std::vector<std::string> TempSpectators;
//            for (int i = 0; i < Players->size(); i++)
//            {
//                Player* p = Players->at(i);
//                if (!mem.IsValidPointer(p->BasePointer))
//					continue;
//                if (p->BasePointer == Myself->BasePointer)
//                    continue;
//                if (!p->IsPlayer())
//					continue;
//                if (p->ViewYaw == 0 || Myself->ViewYaw == 0)
//                    continue;
//                if (std::fabs(p->ViewYaw - Myself->ViewYaw) < 0.1f && p->IsDead)
//                {
//                    //std::cout << u8"Spec: " << p->ViewYaw << u8", Play: " << Myself->ViewYaw << std::endl;
//                    spec_glow = 50;
//                    TempTotalSpectators++;
//                }
//                else
//                {
//                    spec_glow = 0;
//                }
//            }
//
//            TotalSpectators = TempTotalSpectators;
//            Spectators = TempSpectators;
//            LastUpdateTime = Now;
//        }
//    }
//
//
//};

// 定义 Spectator 结构体
struct Spectator {
    // 变量

    // 指向本地玩家对象的指针
    LocalPlayer* Myself;
    // 指向所有玩家对象列表的指针
    std::vector<Player*>* Players;
    // 用于控制观战者高亮的变量
    // 观战者总数
    int TotalSpectators = 0;
    // 观战者名单
    std::vector<std::string> Spectators;
    // 最后一次更新观战者信息的时间
    std::chrono::milliseconds LastUpdateTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    // 构造函数，初始化 Spectator 对象
    Spectator(std::vector<Player*>* Players, LocalPlayer* Myself) {
        this->Players = Players;
        this->Myself = Myself;
    }

    // 更新观战者信息
    void SpectatorsUpdate() {
        std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        if (Now >= LastUpdateTime + std::chrono::milliseconds(1000))
        {
            int TempTotalSpectators = 0;
            std::vector<std::string> TempSpectators;
            for (int i = 0; i < Players->size(); i++)
            {
                Player* p = Players->at(i);
                if (p->IsSpectating()) {
                    TempSpectators.push_back(p->PlayerName);
                    TempTotalSpectators++;
                }
            }

            TotalSpectators = TempTotalSpectators/2;
            Spectators = TempSpectators;
            LastUpdateTime = Now;
        }
    }
};