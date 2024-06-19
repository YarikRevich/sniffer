ssid := $(or $(ssid), '')
password := $(or $(password), '')
country := $(or $(country), '')
channel := $(or $(channel), '')
plugin := $(or $(plugin), '')

.ONESHELL:

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: install
install: ## Installs project to the connected device
ifeq ($(ssid), '')
	@echo "WIFI SSID is not set!"

	@exit 1
endif

ifeq ($(password), '')
	@echo "WIFI password is not set!"

	@exit 1
endif

ifeq ($(country), '')
	@echo "WIFI country is not set!"

	@exit 1
endif

ifeq ($(channel), '')
	@echo "WIFI channel is not set!"

	@exit 1
endif

	CONFIG_WIFI_SSID="$(ssid)" CONFIG_WIFI_PASSWORD="$(password)" CONFIG_WIFI_COUNTRY="$(country)" CONFIG_WIFI_CHANNEL=$(channel) pio run --target=upload

.PHONY: generate
generate: ## Generate ProtocolBuffers files(used mainly for development)
ifeq ($(plugin), '')
	@echo "Plugin is not set!"

	@exit 1
endif

	@protoc -I./resources/proto --pyi_out=./Scripts/server/src/proto data.proto
	@protoc -I./resources/proto --python_out=./Scripts/server/src/proto data.proto
	@protoc --plugin=$(plugin) -I./resources/proto --eams_out=./include/internal/proto/generated data.proto