/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: alerts.proto */

#ifndef PROTOBUF_C_alerts_2eproto__INCLUDED
#define PROTOBUF_C_alerts_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Header Header;
typedef struct _Point Point;
typedef struct _ObjectId ObjectId;
typedef struct _Polygon Polygon;
typedef struct _WarningSettings WarningSettings;
typedef struct _Warnings Warnings;


/* --- enums --- */

typedef enum _OBJECTID {
  OBJECT__ID__PERSON = 0,
  OBJECT__ID__DOG = 1,
  OBJECT__ID__CAT = 2,
  OBJECT__ID__CHAIR = 3,
  OBJECT__ID__CAR = 4,
  OBJECT__ID__BICYCLE = 5
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OBJECT__ID)
} OBJECTID;
typedef enum _OPCODE {
  OPCODE__HEADER = 0,
  OPCODE__ACK = 1,
  OPCODE__NACK = 2,
  OPCODE__WARNINGS_SETTING = 3,
  OPCODE__WARNINGS = 4
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OPCODE)
} OPCODE;

/* --- messages --- */

/*
 */
struct  _Header
{
  ProtobufCMessage base;
  /*
   * Opcode
   */
  OPCODE opcode;
  ProtobufCBinaryData message_data;
};
#define HEADER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&header__descriptor) \
    , 0, {0,NULL} }


struct  _Point
{
  ProtobufCMessage base;
  uint32_t x;
  uint32_t y;
};
#define POINT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&point__descriptor) \
    , 0, 0 }


struct  _ObjectId
{
  ProtobufCMessage base;
  OBJECTID object_id;
  uint32_t confidence;
};
#define OBJECT_ID__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&object_id__descriptor) \
    , 0, 0 }


struct  _Polygon
{
  ProtobufCMessage base;
  size_t n_points;
  Point **points;
  size_t n_object_ids;
  ObjectId **object_ids;
};
#define POLYGON__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&polygon__descriptor) \
    , 0,NULL, 0,NULL }


/*
 */
struct  _WarningSettings
{
  ProtobufCMessage base;
  size_t n_polygons;
  Polygon **polygons;
};
#define WARNING_SETTINGS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&warning_settings__descriptor) \
    , 0,NULL }


struct  _Warnings
{
  ProtobufCMessage base;
  ProtobufCBinaryData wornings;
};
#define WARNINGS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&warnings__descriptor) \
    , {0,NULL} }


/* Header methods */
void   header__init
                     (Header         *message);
size_t header__get_packed_size
                     (const Header   *message);
size_t header__pack
                     (const Header   *message,
                      uint8_t             *out);
size_t header__pack_to_buffer
                     (const Header   *message,
                      ProtobufCBuffer     *buffer);
Header *
       header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   header__free_unpacked
                     (Header *message,
                      ProtobufCAllocator *allocator);
/* Point methods */
void   point__init
                     (Point         *message);
size_t point__get_packed_size
                     (const Point   *message);
size_t point__pack
                     (const Point   *message,
                      uint8_t             *out);
size_t point__pack_to_buffer
                     (const Point   *message,
                      ProtobufCBuffer     *buffer);
Point *
       point__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   point__free_unpacked
                     (Point *message,
                      ProtobufCAllocator *allocator);
/* ObjectId methods */
void   object_id__init
                     (ObjectId         *message);
size_t object_id__get_packed_size
                     (const ObjectId   *message);
size_t object_id__pack
                     (const ObjectId   *message,
                      uint8_t             *out);
size_t object_id__pack_to_buffer
                     (const ObjectId   *message,
                      ProtobufCBuffer     *buffer);
ObjectId *
       object_id__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   object_id__free_unpacked
                     (ObjectId *message,
                      ProtobufCAllocator *allocator);
/* Polygon methods */
void   polygon__init
                     (Polygon         *message);
size_t polygon__get_packed_size
                     (const Polygon   *message);
size_t polygon__pack
                     (const Polygon   *message,
                      uint8_t             *out);
size_t polygon__pack_to_buffer
                     (const Polygon   *message,
                      ProtobufCBuffer     *buffer);
Polygon *
       polygon__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   polygon__free_unpacked
                     (Polygon *message,
                      ProtobufCAllocator *allocator);
/* WarningSettings methods */
void   warning_settings__init
                     (WarningSettings         *message);
size_t warning_settings__get_packed_size
                     (const WarningSettings   *message);
size_t warning_settings__pack
                     (const WarningSettings   *message,
                      uint8_t             *out);
size_t warning_settings__pack_to_buffer
                     (const WarningSettings   *message,
                      ProtobufCBuffer     *buffer);
WarningSettings *
       warning_settings__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   warning_settings__free_unpacked
                     (WarningSettings *message,
                      ProtobufCAllocator *allocator);
/* Warnings methods */
void   warnings__init
                     (Warnings         *message);
size_t warnings__get_packed_size
                     (const Warnings   *message);
size_t warnings__pack
                     (const Warnings   *message,
                      uint8_t             *out);
size_t warnings__pack_to_buffer
                     (const Warnings   *message,
                      ProtobufCBuffer     *buffer);
Warnings *
       warnings__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   warnings__free_unpacked
                     (Warnings *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Header_Closure)
                 (const Header *message,
                  void *closure_data);
typedef void (*Point_Closure)
                 (const Point *message,
                  void *closure_data);
typedef void (*ObjectId_Closure)
                 (const ObjectId *message,
                  void *closure_data);
typedef void (*Polygon_Closure)
                 (const Polygon *message,
                  void *closure_data);
typedef void (*WarningSettings_Closure)
                 (const WarningSettings *message,
                  void *closure_data);
typedef void (*Warnings_Closure)
                 (const Warnings *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    object__id__descriptor;
extern const ProtobufCEnumDescriptor    opcode__descriptor;
extern const ProtobufCMessageDescriptor header__descriptor;
extern const ProtobufCMessageDescriptor point__descriptor;
extern const ProtobufCMessageDescriptor object_id__descriptor;
extern const ProtobufCMessageDescriptor polygon__descriptor;
extern const ProtobufCMessageDescriptor warning_settings__descriptor;
extern const ProtobufCMessageDescriptor warnings__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_alerts_2eproto__INCLUDED */