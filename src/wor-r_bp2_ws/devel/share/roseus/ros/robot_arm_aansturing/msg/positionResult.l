;; Auto-generated. Do not edit!


(when (boundp 'robot_arm_aansturing::positionResult)
  (if (not (find-package "ROBOT_ARM_AANSTURING"))
    (make-package "ROBOT_ARM_AANSTURING"))
  (shadow 'positionResult (find-package "ROBOT_ARM_AANSTURING")))
(unless (find-package "ROBOT_ARM_AANSTURING::POSITIONRESULT")
  (make-package "ROBOT_ARM_AANSTURING::POSITIONRESULT"))

(in-package "ROS")
;;//! \htmlinclude positionResult.msg.html


(defclass robot_arm_aansturing::positionResult
  :super ros::object
  :slots (_arrived ))

(defmethod robot_arm_aansturing::positionResult
  (:init
   (&key
    ((:arrived __arrived) nil)
    )
   (send-super :init)
   (setq _arrived __arrived)
   self)
  (:arrived
   (&optional __arrived)
   (if __arrived (setq _arrived __arrived)) _arrived)
  (:serialization-length
   ()
   (+
    ;; bool _arrived
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _arrived
       (if _arrived (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _arrived
     (setq _arrived (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get robot_arm_aansturing::positionResult :md5sum-) "ea115e3ceb83b7b5fbcc7f283be1718c")
(setf (get robot_arm_aansturing::positionResult :datatype-) "robot_arm_aansturing/positionResult")
(setf (get robot_arm_aansturing::positionResult :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#result definition
bool arrived

")



(provide :robot_arm_aansturing/positionResult "ea115e3ceb83b7b5fbcc7f283be1718c")


