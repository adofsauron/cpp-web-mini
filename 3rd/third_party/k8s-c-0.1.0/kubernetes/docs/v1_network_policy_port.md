# v1_network_policy_port_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**port** | [**object_t**](.md) \* | The port on the given protocol. This can either be a numerical or named port on a pod. If this field is not provided, this matches all port names and numbers. | [optional] 
**protocol** | **char \*** | The protocol (TCP, UDP, or SCTP) which traffic must match. If not specified, this field defaults to TCP. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


