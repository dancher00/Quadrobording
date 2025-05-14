# generated from rosidl_generator_py/resource/_idl.py.em
# with input from unitree_msgs:msg/States.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'qj'
# Member 'vj'
# Member 'tauj'
# Member 'imu_orientation'
# Member 'imu_angular_velocity'
# Member 'imu_linear_acceleration'
# Member 'foot_force_sensor'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_States(type):
    """Metaclass of message 'States'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('unitree_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'unitree_msgs.msg.States')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__states
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__states
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__states
            cls._TYPE_SUPPORT = module.type_support_msg__msg__states
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__states

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class States(metaclass=Metaclass_States):
    """Message class 'States'."""

    __slots__ = [
        '_t',
        '_qj',
        '_vj',
        '_tauj',
        '_imu_orientation',
        '_imu_angular_velocity',
        '_imu_linear_acceleration',
        '_foot_force_sensor',
    ]

    _fields_and_field_types = {
        't': 'double',
        'qj': 'double[12]',
        'vj': 'double[12]',
        'tauj': 'double[12]',
        'imu_orientation': 'double[4]',
        'imu_angular_velocity': 'double[3]',
        'imu_linear_acceleration': 'double[3]',
        'foot_force_sensor': 'double[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 12),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 4),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.t = kwargs.get('t', float())
        if 'qj' not in kwargs:
            self.qj = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.qj = numpy.array(kwargs.get('qj'), dtype=numpy.float64)
            assert self.qj.shape == (12, )
        if 'vj' not in kwargs:
            self.vj = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.vj = numpy.array(kwargs.get('vj'), dtype=numpy.float64)
            assert self.vj.shape == (12, )
        if 'tauj' not in kwargs:
            self.tauj = numpy.zeros(12, dtype=numpy.float64)
        else:
            self.tauj = numpy.array(kwargs.get('tauj'), dtype=numpy.float64)
            assert self.tauj.shape == (12, )
        if 'imu_orientation' not in kwargs:
            self.imu_orientation = numpy.zeros(4, dtype=numpy.float64)
        else:
            self.imu_orientation = numpy.array(kwargs.get('imu_orientation'), dtype=numpy.float64)
            assert self.imu_orientation.shape == (4, )
        if 'imu_angular_velocity' not in kwargs:
            self.imu_angular_velocity = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.imu_angular_velocity = numpy.array(kwargs.get('imu_angular_velocity'), dtype=numpy.float64)
            assert self.imu_angular_velocity.shape == (3, )
        if 'imu_linear_acceleration' not in kwargs:
            self.imu_linear_acceleration = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.imu_linear_acceleration = numpy.array(kwargs.get('imu_linear_acceleration'), dtype=numpy.float64)
            assert self.imu_linear_acceleration.shape == (3, )
        if 'foot_force_sensor' not in kwargs:
            self.foot_force_sensor = numpy.zeros(4, dtype=numpy.float64)
        else:
            self.foot_force_sensor = numpy.array(kwargs.get('foot_force_sensor'), dtype=numpy.float64)
            assert self.foot_force_sensor.shape == (4, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.t != other.t:
            return False
        if all(self.qj != other.qj):
            return False
        if all(self.vj != other.vj):
            return False
        if all(self.tauj != other.tauj):
            return False
        if all(self.imu_orientation != other.imu_orientation):
            return False
        if all(self.imu_angular_velocity != other.imu_angular_velocity):
            return False
        if all(self.imu_linear_acceleration != other.imu_linear_acceleration):
            return False
        if all(self.foot_force_sensor != other.foot_force_sensor):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def t(self):
        """Message field 't'."""
        return self._t

    @t.setter
    def t(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 't' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 't' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._t = value

    @builtins.property
    def qj(self):
        """Message field 'qj'."""
        return self._qj

    @qj.setter
    def qj(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'qj' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'qj' numpy.ndarray() must have a size of 12"
            self._qj = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'qj' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._qj = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def vj(self):
        """Message field 'vj'."""
        return self._vj

    @vj.setter
    def vj(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'vj' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'vj' numpy.ndarray() must have a size of 12"
            self._vj = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'vj' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._vj = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def tauj(self):
        """Message field 'tauj'."""
        return self._tauj

    @tauj.setter
    def tauj(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'tauj' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 12, \
                "The 'tauj' numpy.ndarray() must have a size of 12"
            self._tauj = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 12 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'tauj' field must be a set or sequence with length 12 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._tauj = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def imu_orientation(self):
        """Message field 'imu_orientation'."""
        return self._imu_orientation

    @imu_orientation.setter
    def imu_orientation(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'imu_orientation' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 4, \
                "The 'imu_orientation' numpy.ndarray() must have a size of 4"
            self._imu_orientation = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'imu_orientation' field must be a set or sequence with length 4 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._imu_orientation = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def imu_angular_velocity(self):
        """Message field 'imu_angular_velocity'."""
        return self._imu_angular_velocity

    @imu_angular_velocity.setter
    def imu_angular_velocity(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'imu_angular_velocity' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'imu_angular_velocity' numpy.ndarray() must have a size of 3"
            self._imu_angular_velocity = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'imu_angular_velocity' field must be a set or sequence with length 3 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._imu_angular_velocity = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def imu_linear_acceleration(self):
        """Message field 'imu_linear_acceleration'."""
        return self._imu_linear_acceleration

    @imu_linear_acceleration.setter
    def imu_linear_acceleration(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'imu_linear_acceleration' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'imu_linear_acceleration' numpy.ndarray() must have a size of 3"
            self._imu_linear_acceleration = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'imu_linear_acceleration' field must be a set or sequence with length 3 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._imu_linear_acceleration = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def foot_force_sensor(self):
        """Message field 'foot_force_sensor'."""
        return self._foot_force_sensor

    @foot_force_sensor.setter
    def foot_force_sensor(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'foot_force_sensor' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 4, \
                "The 'foot_force_sensor' numpy.ndarray() must have a size of 4"
            self._foot_force_sensor = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'foot_force_sensor' field must be a set or sequence with length 4 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._foot_force_sensor = numpy.array(value, dtype=numpy.float64)
