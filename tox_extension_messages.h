#pragma once

#include <toxext/toxext.h>

struct ToxExtensionMessages;

/**
 * Callback when message received from friend
 */
typedef void (*tox_extension_messages_received_cb)(uint32_t friend_number,
						   const uint8_t *message,
						   size_t length,
						   void *user_data);

/**
 * Callback when friend receives a message with receipt id receipt_id
 */
typedef void (*tox_extension_messages_receipt_cb)(uint32_t friend_number,
						  const uint64_t receipt_id,
						  void *user_data);

/**
 * Callback on negotiation completion
 */
typedef void (*tox_extension_messages_negotiate_cb)(uint32_t friend_number,
						    bool negotiated,
						    void *user_data);

/**
 * Register a new extension instance with toxext
 */
struct ToxExtensionMessages *tox_extension_messages_register(
	struct ToxExt *toxext, tox_extension_messages_received_cb cb,
	tox_extension_messages_receipt_cb receipt_cb,
	tox_extension_messages_negotiate_cb neg_cb, void *userdata);

/**
 * Free extension handle
 */
void tox_extension_messages_free(struct ToxExtensionMessages *extension);

/**
 * Initiate negotiation with friend_id
 */
void tox_extension_messages_negotiate(struct ToxExtensionMessages *extension,
				      uint32_t friend_id);

/**
 * Append message data to to packet associated with this extension instance
 *
 * Returns an id which will be used in the receipt_cb to indicate the message
 * has been received by the friend
 */
uint64_t tox_extension_messages_append(struct ToxExtensionMessages *extension,
				       struct ToxExtPacketList *packet,
				       uint8_t const *data, size_t size);
