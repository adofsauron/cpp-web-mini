#CXX = clang++
CXXFLAGS = -O2 -ggdb3 -std=gnu++2a -I. -Wall -Wextra -pthread

PREFIX = /usr/local
#PREFIX = $(shell brew --prefix)

OPENSSL_DIR = $(PREFIX)/opt/openssl@1.1
#OPENSSL_DIR = $(PREFIX)/opt/openssl@3
OPENSSL_SUPPORT = -DCPPHTTPLIB_OPENSSL_SUPPORT -I$(OPENSSL_DIR)/include -L$(OPENSSL_DIR)/lib -lssl -lcrypto

ZLIB_SUPPORT = -DCPPHTTPLIB_ZLIB_SUPPORT -lz

BROTLI_DIR = $(PREFIX)/opt/brotli
BROTLI_SUPPORT = -DCPPHTTPLIB_BROTLI_SUPPORT -I$(BROTLI_DIR)/include -L$(BROTLI_DIR)/lib -lbrotlicommon -lbrotlienc -lbrotlidec
PROTOBUF_SUPPORT = -L/usr/local/lib -lprotobuf
LIBGO_SUPPORT = -I/usr/local/include -L/usr/local/lib -llibgo -ldl
BOOST_SUPPORT = -lboost_coroutine -lboost_thread -lboost_system
LOG4CPP_SUPPORT = -I/usr/local/include/orocos -L/usr/local/lib -lorocos-log4cpp

GRPC_SUPPORT = -I/usr/local/include \
				-L/usr/local/lib \
				/usr/local/lib/libgrpc++.a \
				/usr/local/lib/libgrpc.a \
				/usr/local/lib/libgrpc++_alts.a \
				/usr/local/lib/libgrpc++_error_details.a \
				/usr/local/lib/libgrpc_plugin_support.a \
				/usr/local/lib/libgrpcpp_channelz.a \
				/usr/local/lib/libgrpc++_unsecure.a \
				/usr/local/lib/libgrpc_unsecure.a \
				/usr/local/lib/libgrpc++_reflection.a \
				/usr/local/lib64/libprotobuf.a \
				/usr/local/lib/libgrpc.a \
				/usr/local/lib/libz.a \
				/usr/local/lib/libcares.a \
				/usr/local/lib/libaddress_sorting.a \
				/usr/local/lib/libre2.a \
				/usr/local/lib64/libabsl_raw_hash_set.a \
				/usr/local/lib64/libabsl_hashtablez_sampler.a \
				/usr/local/lib64/libabsl_hash.a \
				/usr/local/lib64/libabsl_city.a \
				/usr/local/lib64/libabsl_low_level_hash.a \
				/usr/local/lib64/libabsl_statusor.a \
				/usr/local/lib64/libabsl_bad_variant_access.a \
				/usr/local/lib/libgpr.a \
				/usr/local/lib/libupb.a \
				/usr/local/lib64/libabsl_status.a \
				/usr/local/lib64/libabsl_random_distributions.a \
				/usr/local/lib64/libabsl_random_seed_sequences.a \
				/usr/local/lib64/libabsl_random_internal_pool_urbg.a \
				/usr/local/lib64/libabsl_random_internal_randen.a \
				/usr/local/lib64/libabsl_random_internal_randen_hwaes.a \
				/usr/local/lib64/libabsl_random_internal_randen_hwaes_impl.a \
				/usr/local/lib64/libabsl_random_internal_randen_slow.a \
				/usr/local/lib64/libabsl_random_internal_platform.a \
				/usr/local/lib64/libabsl_random_internal_seed_material.a \
				/usr/local/lib64/libabsl_random_seed_gen_exception.a \
				/usr/local/lib64/libabsl_cord.a \
				/usr/local/lib64/libabsl_bad_optional_access.a \
				/usr/local/lib64/libabsl_cordz_info.a \
				/usr/local/lib64/libabsl_cord_internal.a \
				/usr/local/lib64/libabsl_cordz_functions.a \
				/usr/local/lib64/libabsl_exponential_biased.a \
				/usr/local/lib64/libabsl_cordz_handle.a \
				/usr/local/lib64/libabsl_str_format_internal.a \
				/usr/local/lib64/libabsl_synchronization.a \
				/usr/local/lib64/libabsl_stacktrace.a \
				/usr/local/lib64/libabsl_symbolize.a \
				/usr/local/lib64/libabsl_debugging_internal.a \
				/usr/local/lib64/libabsl_demangle_internal.a \
				/usr/local/lib64/libabsl_graphcycles_internal.a \
				/usr/local/lib64/libabsl_malloc_internal.a \
				/usr/local/lib64/libabsl_time.a \
				/usr/local/lib64/libabsl_strings.a \
				/usr/local/lib64/libabsl_throw_delegate.a \
				/usr/local/lib64/libabsl_int128.a \
				/usr/local/lib64/libabsl_strings_internal.a \
				/usr/local/lib64/libabsl_base.a \
				/usr/local/lib64/libabsl_spinlock_wait.a \
				/usr/local/lib64/libabsl_raw_logging_internal.a \
				/usr/local/lib64/libabsl_log_severity.a \
				/usr/local/lib64/libabsl_civil_time.a \
				/usr/local/lib64/libabsl_time_zone.a \
				/usr/local/lib/libssl.a \
				/usr/local/lib/libcrypto.a 


SRC = src/run/run.cc \
		src/http/httpserver.cc \
		src/ins_rpc_svr/ins_rpc_svr.cc \
		src/proc/heart_beat.cc \
		src/logger/logger.cc \
		src/router/router.cc \
		src/router/router_test.cc \
		src/proto/hello.pb.cc \
		src/proto/hello.grpc.pb.cc 


TARGET = ins_svr

all: ${TARGET}

ins_svr : ${SRC} Makefile
	$(CXX) -o ${TARGET} \
		$(CXXFLAGS) \
		${SRC} \
		${LOG4CPP_SUPPORT} \
		${BOOST_SUPPORT} \
		${LIBGO_SUPPORT} \
		${PROTOBUF_SUPPORT} \
		$(ZLIB_SUPPORT) \
		$(BROTLI_SUPPORT) \
		$(GRPC_SUPPORT) 

pem:
	openssl genrsa 2048 > key.pem
	openssl req -new -key key.pem | openssl x509 -days 3650 -req -signkey key.pem > cert.pem

clean:
	rm ${TARGET} -f
