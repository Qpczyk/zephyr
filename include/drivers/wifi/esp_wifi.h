/*
 * Copyright (c) 2021 Grinn
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_WIFI_H_
#define ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_WIFI_H_

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

void esp_wifi_dhcp_enable(const struct device *dev);
int esp_wifi_set_static_addr(const struct device *dev,
			     enum esp_iface_type type, struct in_addr *ip,
			     struct in_addr *gw, struct in_addr *nm);
int esp_wifi_get_at_version(const struct device *dev, uint8_t *dst,
			    uint8_t dst_size);

#if defined(CONFIG_WIFI_ESP_ETH_SUPPORT)
void esp_wifi_suspend_eth(const struct device *dev, bool suspend);
bool esp_wifi_is_eth_suspended(const struct device *dev);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_WIFI_H_ */
