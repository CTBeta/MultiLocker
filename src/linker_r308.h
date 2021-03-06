/**
 * @brief Linker for R308 module
 *
 * @file linker_r308.h
 * @author Jason C.H
 * @date 2018-09-01
 */
#ifndef LINKER_R308_H
#define LINKER_R308_H

#include <EEPROM.h>
#include <r308.h>
#include "linker.h"
#include "user.hpp"

class R308Linker : public Linker {
 private:
  R308 r308;

  /**
   * @brief Read latest fingerprint location from EEPROM.
   * @brief 从EEPROM中读取最新指纹位置
   *
   * @param role User role.用户组
   * @return uint16_t Location.指纹位置
   */
  uint16_t ReadFromEEPROM(UserRole role);

  /**
   * Save latest fingerprint location to EEPROM.
   * 在EEPROM中保存最新指纹位置
   */
  void SaveToEEPROM(UserRole role, uint16_t location);

  /**
   * @brief Locate user role by fingerprint page ID
   * @brief 根据指纹存储位置确定用户组
   *
   * @param pageID Fingerprint page ID.指纹库位置
   * @return UserRole User role.用户组
   */
  UserRole GetUserRole(uint16_t pageID);

  /**
   * @brief Locate user role range max
   * @brief 根据用户组确定指纹库区间上限
   *
   * @param role User role.用户组
   * @return uint16_t Page location.指纹库位置
   */
  uint16_t GetRoleLocationRangeMax(UserRole role);

  /**
   * @brief Locate user role range min
   * @brief 根据用户组确定指纹库区间下限
   *
   * @param role role User role.用户组
   * @return uint16_t Page location.指纹库位置
   */
  uint16_t GetRoleLocationRangeMin(UserRole role);

 public:
  R308Linker();
  ~R308Linker();

  /**
   * @brief Init module.
   * @brief 初始化模块
   */
  void Init();

  /**
   * @brief Get user from modules and return
   * @brief 从模块获取用户并返回
   *
   * @return User The user got from modules
   */
  User GetUser();

  /**
   * @brief Auth user with given role.
   * @brief 用户认证
   *
   * @param user The user under match.等待比对的用户
   * @param role The role to match.等待比对的用户组
   * @return true Role match succeed.比对成功
   * @return false Role match failed.比对失败
   */
  bool Auth(User &user, const UserRole &role);

  /**
   * @brief Module setup mode
   * @brief 模块配置模式
   */
  void SetupMode();

  /**
   * @brief Register new user to given role
   * @brief 注册新用户到给定用户组
   *
   * @param role User role.用户组
   * @return true Register succeed.注册成功
   * @return false Register failed.注册失败
   */
  bool RegisterUser(const UserRole &role);

  /**
   * @brief Delete user
   * @brief 移除用户
   *
   * @param user User to delete.待删除的用户
   * @return true Delete succeed.移除成功
   * @return false Delete failed.移除失败
   */
  bool DeleteUser(User &user);
};

#endif