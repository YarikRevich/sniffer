#include "internal/core/core.h"


char* Core::get_hash(unsigned char *src, int size) {
    char *result = new char[MD5_SIZE];

    uint8_t pkt_hash[16];

    md5((uint8_t *)src, size, pkt_hash);

    sprintf(result, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            pkt_hash[0], pkt_hash[1], pkt_hash[2], pkt_hash[3], pkt_hash[4], pkt_hash[5],
            pkt_hash[6], pkt_hash[7], pkt_hash[8], pkt_hash[9], pkt_hash[10], pkt_hash[11],
            pkt_hash[12], pkt_hash[13], pkt_hash[14], pkt_hash[15]);

    return result;
};

char* Core::get_ssid(unsigned char *src, uint8_t size) {
    char *result = new char[SSID_MAX_SIZE];

    int i, j;

    for(i = 26, j = 0; i < 26 + size; i++, j++){
        result[j] = src[i];
    }

    result[j] = '\0';

    return result;
};

int Core::get_sequence(unsigned char *src) {
    int result;

    char num[5] = "\0";

    sprintf(num, "%02x%02x", src[22], src[23]);
    sscanf(num, "%x", &result);

    return result;
};

char* Core::get_ht(unsigned char *src, int packet_size, int ssid_size) {
    char *result = new char[5];

    int ht_start = 25 + ssid_size + 19;

    if(src[ht_start - 1] > 0 && ht_start < packet_size - 4){
        if(src[ht_start - 4] == 1)
            sprintf(result, "%02x%02x", src[ht_start+3], src[ht_start+1+3]);
        else {
            sprintf(result, "%02x%02x", src[ht_start], src[ht_start+1]);
        }
    }

    return result;
};


//
//static void wifi_sniffer_init(void);
//static void wifi_sniffer_packet_handler(void *buff, wifi_promiscuous_pkt_type_t type);
//static void get_hash(unsigned char *data, int len_res, char hash[MD5_LEN]);
//static void get_ssid(unsigned char *data, char ssid[SSID_MAX_LEN], uint8_t ssid_len);
//static int get_sn(unsigned char *data);
//static void get_ht_capabilites_info(unsigned char *data, char htci[5], int pkt_len, int ssid_len);
//
//static void wifi_connect_init(void);
//
//static void wifi_connect_init() {
//    esp_netif_init();
//
//    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//    esp_wifi_init(&cfg);
//    esp_wifi_set_storage(WIFI_STORAGE_RAM);
//    esp_wifi_set_mode(WIFI_MODE_APSTA);
//
//    wifi_config_t wifi_config = {
//            .sta = {
//                    .ssid = CONFIG_WIFI_SSID,
//                    .password = CONFIG_WIFI_PASSWORD,
//            },
//    };
//
//    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
//    esp_wifi_start();
//}
//
//static void wifi_sniffer_init() {
//    esp_netif_init();
//
//    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
//    esp_wifi_init(&cfg);
//
//    const wifi_country_t wifi_country = {
//            .cc = CONFIG_WIFI_COUNTRY,
//            .schan = 1,
//            .nchan = 13,
//            .policy = WIFI_COUNTRY_POLICY_AUTO
//    };
//
//    esp_wifi_set_country(&wifi_country);
//    esp_wifi_set_storage(WIFI_STORAGE_RAM);
//    esp_wifi_set_mode(WIFI_MODE_NULL);
//    esp_wifi_start();
//
//    const wifi_promiscuous_filter_t filt = {
//            .filter_mask = WIFI_EVENT_MASK_AP_PROBEREQRECVED
//    };
//
//    esp_wifi_set_promiscuous_filter(&filt);
//    esp_wifi_set_promiscuous_rx_cb(wifi_sniffer_packet_handler);
//    esp_wifi_set_promiscuous(true);
//
//    esp_wifi_set_channel(CONFIG_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE); //only set the primary channel
//}
//
//static void wifi_sniffer_packet_handler(void* buff, wifi_promiscuous_pkt_type_t type) {
//    int pkt_len, fc, sn=0;
//
//    char ssid[SSID_MAX_LEN] = "\0", hash[MD5_LEN] = "\0", htci[5] = "\0";
//
//    uint8_t ssid_len;
//    time_t ts;
//
//    wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buff;
//    wifi_mgmt_hdr *mgmt = (wifi_mgmt_hdr *)pkt->payload;
//
//    fc = ((uint16_t)(mgmt->fctl));
//
//    if((fc & 0xFF00) == 0x4000){
//        time(&ts);
//
//        ssid_len = pkt->payload[25];
//        if(ssid_len > 0)
//            get_ssid(pkt->payload, ssid, ssid_len);
//
//        pkt_len = pkt->rx_ctrl.sig_len;
//        get_hash(pkt->payload, pkt_len-4, hash);
//
//        sn = get_sn(pkt->payload);
//
//        get_ht_capabilites_info(pkt->payload, htci, pkt_len, ssid_len);
//
////        ESP_LOGI(TAG, "ADDR=%02x:%02x:%02x:%02x:%02x:%02x, "
////                      "SSID=%s, "
////                      "TIMESTAMP=%d, "
////                      "HASH=%s, "
////                      "RSSI=%02d, "
////                      "SN=%d, "
////                      "HT CAP. INFO=%s",
////                 mgmt->sa[0], mgmt->sa[1], mgmt->sa[2], mgmt->sa[3], mgmt->sa[4], mgmt->sa[5],
////                 ssid,
////                 (int)ts,
////                 hash,
////                 pkt->rx_ctrl.rssi,
////                 sn,
////                 htci);
//
//        // save_pkt_info(mgmt->sa, ssid, ts, hash, pkt->rx_ctrl.rssi, sn, htci);
//    }
//}
//
//static void get_hash(unsigned char *data, int len_res, char hash[MD5_LEN])
//{
//    uint8_t pkt_hash[16];
//
//    md5((uint8_t *)data, len_res, pkt_hash);
//
//    sprintf(hash, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
//            pkt_hash[0], pkt_hash[1], pkt_hash[2], pkt_hash[3], pkt_hash[4], pkt_hash[5],
//            pkt_hash[6], pkt_hash[7], pkt_hash[8], pkt_hash[9], pkt_hash[10], pkt_hash[11],
//            pkt_hash[12], pkt_hash[13], pkt_hash[14], pkt_hash[15]);
//}
//
//static void get_ssid(unsigned char *data, char ssid[SSID_MAX_LEN], uint8_t ssid_len) {
//    int i, j;
//
//    for(i=26, j=0; i<26+ssid_len; i++, j++){
//        ssid[j] = data[i];
//    }
//
//    ssid[j] = '\0';
//}
//
//static int get_sn(unsigned char *data) {
//    int sn;
//    char num[5] = "\0";
//
//    sprintf(num, "%02x%02x", data[22], data[23]);
//    sscanf(num, "%x", &sn);
//
//    return sn;
//}
//
//static void get_ht_capabilites_info(unsigned char *data, char htci[5], int pkt_len, int ssid_len)
//{
//    int ht_start = 25+ssid_len+19;
//
//    /* 1) data[ht_start-1] is the byte that says if HT Capabilities is present or not (tag length).
//     * 2) I need to check also that i'm not outside the payload: if HT Capabilities is not present in the packet,
//     * for this reason i'm considering the ht_start must be lower than the total length of the packet less the last 4 bytes of FCS */
//
//    if(data[ht_start-1]>0 && ht_start<pkt_len-4){ //HT capabilities is present
//        if(data[ht_start-4] == 1) //DSSS parameter is set -> need to shift of three bytes
//            sprintf(htci, "%02x%02x", data[ht_start+3], data[ht_start+1+3]);
//        else {
//            sprintf(htci, "%02x%02x", data[ht_start], data[ht_start+1]);
//        }
//    }
//}