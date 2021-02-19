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
};

void esp_wifi_dhcp_enable(const struct device *dev);
int esp_wifi_set_static_addr(const struct device *dev,
			     enum esp_iface_type type, struct in_addr *ip,
			     struct in_addr *gw, struct in_addr *nm);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_DRIVERS_WIFI_ESP_WIFI_H_ */
