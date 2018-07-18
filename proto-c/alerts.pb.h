/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.0-dev at Wed Jul 18 14:16:52 2018. */

#ifndef PB_ALERTS_PB_H_INCLUDED
#define PB_ALERTS_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _OBJECT_ID {
    OBJECT_ID_PERSON = 0,
    OBJECT_ID_DOG = 1,
    OBJECT_ID_CAT = 2,
    OBJECT_ID_CHAIR = 3,
    OBJECT_ID_CAR = 4,
    OBJECT_ID_BICYCLE = 5
} OBJECT_ID;
#define _OBJECT_ID_MIN OBJECT_ID_PERSON
#define _OBJECT_ID_MAX OBJECT_ID_BICYCLE
#define _OBJECT_ID_ARRAYSIZE ((OBJECT_ID)(OBJECT_ID_BICYCLE+1))

typedef enum _OPCODE {
    OPCODE_HEADER = 0,
    OPCODE_ACK = 1,
    OPCODE_NACK = 2,
    OPCODE_POLYGON_SETTING = 3,
    OPCODE_WARNINGS = 4
} OPCODE;
#define _OPCODE_MIN OPCODE_HEADER
#define _OPCODE_MAX OPCODE_WARNINGS
#define _OPCODE_ARRAYSIZE ((OPCODE)(OPCODE_WARNINGS+1))

/* Struct definitions */
typedef struct _ObjectId {
    OBJECT_ID object_id;
    uint32_t confidence;
    uint32_t majority_count;
    uint32_t majority_min;
/* @@protoc_insertion_point(struct:ObjectId) */
} ObjectId;

typedef struct _Point {
    uint32_t x;
    uint32_t y;
/* @@protoc_insertion_point(struct:Point) */
} Point;

typedef struct _Warning {
    uint32_t id;
    pb_callback_t points;
    pb_callback_t object_ids;
/* @@protoc_insertion_point(struct:Warning) */
} Warning;

typedef struct _Warnings {
    uint32_t warnings;
/* @@protoc_insertion_point(struct:Warnings) */
} Warnings;

/* Default values for struct fields */

/* Initializer values for message structs */
#define Point_init_default                       {0, 0}
#define ObjectId_init_default                    {_OBJECT_ID_MIN, 0, 0, 0}
#define Warning_init_default                     {0, {{NULL}, NULL}, {{NULL}, NULL}}
#define Warnings_init_default                    {0}
#define Point_init_zero                          {0, 0}
#define ObjectId_init_zero                       {_OBJECT_ID_MIN, 0, 0, 0}
#define Warning_init_zero                        {0, {{NULL}, NULL}, {{NULL}, NULL}}
#define Warnings_init_zero                       {0}

/* Field tags (for use in manual encoding/decoding) */
#define ObjectId_object_id_tag                   1
#define ObjectId_confidence_tag                  2
#define ObjectId_majority_count_tag              3
#define ObjectId_majority_min_tag                4
#define Point_x_tag                              1
#define Point_y_tag                              2
#define Warning_id_tag                           1
#define Warning_points_tag                       2
#define Warning_object_ids_tag                   3
#define Warnings_warnings_tag                    1

/* Struct field encoding specification for nanopb */
extern const pb_field_t Point_fields[3];
extern const pb_field_t ObjectId_fields[5];
extern const pb_field_t Warning_fields[4];
extern const pb_field_t Warnings_fields[2];

/* Maximum encoded size of messages (where known) */
#define Point_size                               12
#define ObjectId_size                            20
/* Warning_size depends on runtime parameters */
#define Warnings_size                            6

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ALERTS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
