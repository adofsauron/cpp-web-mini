#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>


struct ConfigData 
{
    std::string TenantId;
    std::string PodName;
    std::string ServerName;
    std::string ServiceName;
    std::string ClusterId;
    std::string ManageUrl;
    std::string InstanceID;


    int Replicas;
    int PodIndex;
    int CheckClusterStatusInterval;
    int ServicePort;

    ConfigData()
        : Replicas(0)
        , PodIndex(0)
        , CheckClusterStatusInterval(10)
        , ServicePort(8080)
    {
    }
}; 


int InitConfig();

const ConfigData& GetConfig();


#endif /* __CONFIG_H__ */
