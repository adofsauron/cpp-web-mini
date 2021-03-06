/*
 * Autogenerated from the following JSON policy
 */

#if 0


 Original JSON size: 706
#endif


static const lws_ss_metadata_t _md_default_ua = {
	.name = "ua",
	.value__may_own_heap = (void *)"user-agent",
	.value_length = 0xa,
	.length = 0,
	.value_is_http_token = 0x45,
},
_md_default_acc = {
	.next = (void *)&_md_default_ua,
	.name = "acc",
	.value__may_own_heap = (void *)"accept",
	.value_length = 0x6,
	.length = 1,
	.value_is_http_token = 0x11,
},
_md_default_endpoint = {
	.next = (void *)&_md_default_acc,
	.name = "endpoint",
	.value__may_own_heap = (void *)"",
	.value_length = 0x0,
	.length = 2,
	.value_is_http_token = 0x0,
};

static const uint32_t _rbo_bo_0[] = {
 1000, 
};
static const lws_retry_bo_t _rbo_0 = {
	.retry_ms_table = _rbo_bo_0,
	.retry_ms_table_count = 1,
	.conceal_count = 25,
	.secs_since_valid_ping = 30,
	.secs_since_valid_hangup = 35,
	.jitter_percent = 20,
};

static const lws_ss_policy_t _ssp_captive_portal_detect = {
	.streamtype = "captive_portal_detect",
	.endpoint = "connectivitycheck.android.com",
	.u = {
		.http = {
			.method = "GET",
			.url = "generate_204",
			.resp_expect = 204,
			.fail_redirect = 1,
		}
	},
	.flags = 0x1,
	.priority = 0x0,
	.port = 80,
	.protocol = 0,
},
_ssp_default = {
	.next = (void *)&_ssp_captive_portal_detect,
	.streamtype = "__default",
	.endpoint = "${endpoint}",
	.metadata = (void *)&_md_default_endpoint,
	.u = {
		.http = {
			.method = "GET",
			.url = "",
		}
	},
	.retry_bo = &_rbo_0,
	.flags = 0x10311,
	.priority = 0x0,
	.port = 443,
	.metadata_count = 3,
	.protocol = 1,
};
#define _ss_static_policy_entry _ssp_default
/* estimated footprint 676 (when sizeof void * = 8) */
