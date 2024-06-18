plugin := $(or $(plugin), '')

.ONESHELL:

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: install
install: ## Installs project to the connected device
	CONFIG_WIFI_SSID="503" CONFIG_WIFI_PASSWORD="503a503b" CONFIG_WIFI_COUNTRY="PL" CONFIG_WIFI_CHANNEL=11 pio run --target=upload

#build_flags = -DCONFIG_WIFI_SSID=${env.CONFIG_WIFI_SSID} -DCONFIG_WIFI_PASSWORD=${env.CONFIG_WIFI_PASSWORD} -DCONFIG_WIFI_COUNTRY=${env.CONFIG_WIFI_COUNTRY}

.PHONY: generate
generate: ## Generate ProtocolBuffers files(used mainly for development)
ifeq ($(plugin), '')
	@echo "Plugin is not set!"

	@exit 1
endif

	@protoc -I./resources/proto --pyi_out=./Scripts/server/src/proto data.proto
	@protoc -I./resources/proto --python_out=./Scripts/server/src/proto data.proto
	@protoc --plugin=$(plugin) -I./resources/proto --eams_out=./Core/External/Proto/Generated data.proto