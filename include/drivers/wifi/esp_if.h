/*
 * Copyright (c) 2021 Grinn
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_IF_H_
#define ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_IF_H_

#include <device.h>
#include <net/net_ip.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum esp_iface_type {
	ESP_IFACE_WIFI,
#if defined(CONFIG_WIFI_ESP_ETH_SUPPORT)
	ESP_IFACE_ETH,
#endif
};

#if defined(CONFIG_WIFI_ESP_ETH_SUPPORT)
void esp_cfg_suspend_eth(const struct device *dev, bool suspend);
#endif
void esp_if_use_static_addr(const struct device *dev,
			    bool use_static);
void esp_if_set_static_addr(const struct device *dev,
			    enum esp_iface_type type,
			    struct in_addr *ip, struct in_addr *gw,
			    struct in_addr *nm);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_IF_H_ */