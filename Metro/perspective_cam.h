struct Vector3;
float dot(Vector3 a,Vector3 b);
struct Vector3 {
	float x, y, z;
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float x_, float y_, float z_):x(x_), y(y_), z(z_){}

	Vector3 operator+(const Vector3& other) const
	{
		return Vector3( x + other.x, y + other.y, z + other.z );
	}


	Vector3 operator-(const Vector3& other) const
	{
		return Vector3( x - other.x, y - other.y, z - other.z );
	}

	Vector3 operator*(float scale) const
	{
		return Vector3( x * scale, y * scale, z * scale );
	}

	void normalize()
	{
		float length = std::sqrt(x * x + y * y + z * z);
		x /= length;
		y /= length;
		z /= length;
	}

	Vector3 rotate(const Vector3& axis, float angle) const
	{
		float s = std::sin(angle);
		float c = std::cos(angle);

		Vector3 u = axis * (dot((*this), axis));
		Vector3 v = (*this) - u;
		Vector3 w = axis.cross(v);

		return u + v * c + w * s;
	}


	Vector3 cross(const Vector3& other) const
	{
		return Vector3(y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}


	Vector3& operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	Vector3 normalized() const
	{
		float length = std::sqrt(x * x + y * y + z * z);
		return Vector3( x / length, y / length, z / length);
	}

};


class Camera {
public:
	Vector3 m_position, m_direction, m_up, m_right;

	Camera()
		: m_position(0.0f, 0.0f, 0.0f)
		, m_direction(0.0f, 0.0f, -1.0f)
		, m_up(0.0f, 1.0f, 0.0f)
		, m_right(1.0f, 0.0f, 0.0f)
	{
	}
	
	void updateRight()
	{
		m_right = m_direction.cross(m_up);
		m_right.normalize();
	}


	void setPosition(float x, float y, float z)
	{
		m_position = Vector3( x, y, z );
	}

	void setDirection(float x, float y, float z)
	{
		m_direction = Vector3( x, y, z );
		m_direction.normalize();
		updateRight();
	}

	void moveForward(float distance)
	{
		m_position += m_direction * distance;
	}

	void moveRight(float distance)
	{
		m_position += m_right * distance;
	}

	void moveUp(float distance)
	{
		m_position += m_up * distance;
	}

	void rotateX(float angle)
	{
		m_direction = m_direction.rotate(m_right, angle);
		m_up = m_up.rotate(m_right, angle);
		updateRight();
	}

	void rotateY(float angle)
	{
		m_direction = m_direction.rotate(m_up, angle);
		m_right = m_right.rotate(m_up, angle);
	}

	void rotateZ(float angle)
	{
		m_right = m_right.rotate(m_direction, angle);
		m_up = m_up.rotate(m_direction, angle);
	}

	void look() const
	{
		 gluLookAt(m_position.x, m_position.y, m_position.z,
              m_position.x + m_direction.x, m_position.y + m_direction.y, m_position.z + m_direction.z,
              m_up.x, m_up.y, m_up.z);
	}


};

float dot(Vector3 a,Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}



