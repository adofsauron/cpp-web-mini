# v1_token_review_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**audiences** | **list_t \*** | Audiences is a list of the identifiers that the resource server presented with the token identifies as. Audience-aware token authenticators will verify that the token was intended for at least one of the audiences in this list. If no audiences are provided, the audience will default to the audience of the Kubernetes apiserver. | [optional] 
**token** | **char \*** | Token is the opaque bearer token. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


