; Auto-generated. Do not edit!


(cl:in-package robot_arm_aansturing-srv)


;//! \htmlinclude Test-request.msg.html

(cl:defclass <Test-request> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:integer
    :initform 0)
   (b
    :reader b
    :initarg :b
    :type cl:integer
    :initform 0))
)

(cl:defclass Test-request (<Test-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Test-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Test-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<Test-request> is deprecated: use robot_arm_aansturing-srv:Test-request instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <Test-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:a-val is deprecated.  Use robot_arm_aansturing-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <Test-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:b-val is deprecated.  Use robot_arm_aansturing-srv:b instead.")
  (b m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Test-request>) ostream)
  "Serializes a message object of type '<Test-request>"
  (cl:let* ((signed (cl:slot-value msg 'a)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'b)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Test-request>) istream)
  "Deserializes a message object of type '<Test-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'a) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'b) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Test-request>)))
  "Returns string type for a service object of type '<Test-request>"
  "robot_arm_aansturing/TestRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Test-request)))
  "Returns string type for a service object of type 'Test-request"
  "robot_arm_aansturing/TestRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Test-request>)))
  "Returns md5sum for a message object of type '<Test-request>"
  "6a2e34150c00229791cc89ff309fff21")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Test-request)))
  "Returns md5sum for a message object of type 'Test-request"
  "6a2e34150c00229791cc89ff309fff21")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Test-request>)))
  "Returns full string definition for message of type '<Test-request>"
  (cl:format cl:nil "int64 a~%int64 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Test-request)))
  "Returns full string definition for message of type 'Test-request"
  (cl:format cl:nil "int64 a~%int64 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Test-request>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Test-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Test-request
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
))
;//! \htmlinclude Test-response.msg.html

(cl:defclass <Test-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass Test-response (<Test-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Test-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Test-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_arm_aansturing-srv:<Test-response> is deprecated: use robot_arm_aansturing-srv:Test-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <Test-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_arm_aansturing-srv:sum-val is deprecated.  Use robot_arm_aansturing-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Test-response>) ostream)
  "Serializes a message object of type '<Test-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Test-response>) istream)
  "Deserializes a message object of type '<Test-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Test-response>)))
  "Returns string type for a service object of type '<Test-response>"
  "robot_arm_aansturing/TestResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Test-response)))
  "Returns string type for a service object of type 'Test-response"
  "robot_arm_aansturing/TestResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Test-response>)))
  "Returns md5sum for a message object of type '<Test-response>"
  "6a2e34150c00229791cc89ff309fff21")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Test-response)))
  "Returns md5sum for a message object of type 'Test-response"
  "6a2e34150c00229791cc89ff309fff21")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Test-response>)))
  "Returns full string definition for message of type '<Test-response>"
  (cl:format cl:nil "int64 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Test-response)))
  "Returns full string definition for message of type 'Test-response"
  (cl:format cl:nil "int64 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Test-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Test-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Test-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Test)))
  'Test-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Test)))
  'Test-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Test)))
  "Returns string type for a service object of type '<Test>"
  "robot_arm_aansturing/Test")