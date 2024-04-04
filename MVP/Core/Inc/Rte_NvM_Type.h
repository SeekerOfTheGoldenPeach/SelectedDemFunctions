#include <stdint.h>

#define NVM_REQ_OK (0x00u)
#define NVM_REQ_NOT_OK (0x01u)
#define NVM_REQ_PENDING (0x02u)
#define NVM_REQ_INTEGRITY_FAILED (0x03u)
#define NVM_REQ_BLOCK_SKIPPED (0x04u)
#define NVM_REQ_NV_INVALIDATED (0x05u)
#define NVM_REQ_CANCELED (0x06u)
#define NVM_REQ_RESTORED_DEFAULTS (0x08u)

#define NVM_INIT_READ_BLOCK (0x00u)
#define NVM_INIT_RESTORE_BLOCK_DEFAULTS (0x01u)
#define NVM_INIT_READ_ALL_BLOCK (0x02u)
#define NVM_INIT_FIRST_INIT_ALL (0x03u)

typedef uint16_t NvM_BlockIdType;

typedef uint8_t NvM_RequestResultType;

typedef uint8_t NvM_InitBlockRequestType;
