#include <string>
#include <vector>

#include "config.h"
#include "../logger/logger.h"
#include "../tools/tools.h"

static ConfigData __config_data;


const ConfigData& GetConfig()
{
    return __config_data;
}

template <typename T>
bool getValueFromEnv(T& value, const char* envName,  bool canNil)
{
    LogInstance().info("get config evnName = [%s], unknown type", envName);
    return true;
}


template <>
bool getValueFromEnv(std::string& value, const char* envName,  bool canNil)
{
    value = std::getenv(envName);
    LogInstance().info("get config evnName = [%s], value = [%s]", envName, value.c_str());

    if (canNil) {
        return true;
    }

    if (value.empty()) {
        LogInstance().notice("config nil value, evnName = [%s]", envName);
        exit(-1);
        return false;
    }

    return true;
}

template <>
bool getValueFromEnv(int& value, const char* envName,  bool canNil)
{
    std::string value_str = std::getenv(envName);
    LogInstance().info("get config evnName = [%s], value = [%s]", envName, value_str.c_str());

    if (canNil) {
        return true;
    }

    if (value_str.empty()) {
        LogInstance().notice("config nil value, evnName = [%s]", envName);
        exit(-1);
        return false;
    }

    value = std::atoi(value_str.c_str());
    LogInstance().info("get config int evnName = [%s], value = [%d]", envName, value);
    return true;
}

int InitConfig()
{
    getValueFromEnv(__config_data.TenantId, "TENANT_ID", false);
    getValueFromEnv(__config_data.Replicas, "REPLICAS", false);
    getValueFromEnv(__config_data.PodName, "POD_NAME", false);
    getValueFromEnv(__config_data.ManageUrl, "MANAGE_URL", false);
    getValueFromEnv(__config_data.InstanceID, "CLUSTER_ID", false);
    getValueFromEnv(__config_data.ClusterId, "CLUSTER_ID", false);
    getValueFromEnv(__config_data.CheckClusterStatusInterval, "CHECK_CLUSTER_INTERVAL", false);
    getValueFromEnv(__config_data.ServicePort, "SERVER_PORT", false);

    std::vector<std::string> pod_vec = splitString(__config_data.PodName, "-");
    const std::string& pod_vec_last = pod_vec.back();
    if (!pod_vec_last.empty()) {
        __config_data.PodIndex = std::atoi(pod_vec_last.c_str());
        LogInstance().info("get config evnName = [%s], value = [%d]", "PodIndex", __config_data.PodIndex);
    }

    return 0;
}

