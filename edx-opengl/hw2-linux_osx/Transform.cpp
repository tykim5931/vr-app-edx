// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
  mat3 ret;
  //Rodriques' rotation formula: cos(degrees) +sin(degrees)A* + (1 - cos(degrees))(axis(transpose(axis))
	vec3 axisr = glm::normalize(axis);
	float radians = (pi / 180) * degrees; 
	ret = 
		glm::cos(radians) * mat3(1) 
		+ glm::sin(radians) * mat3(0, -axisr.z, axisr.y, axisr.z, 0, -axisr.x, -axisr.y, axisr.x, 0)
		+ (1 - glm::cos(radians)) * mat3(axisr.x * axisr.x, axisr.x * axisr.y, axisr.x * axisr.z, axisr.x * axisr.y, axisr.y * axisr.y, axisr.y * axisr.z, axisr.x * axisr.z, axisr.y * axisr.z, axisr.z * axisr.z);
  return ret;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
	eye = Transform::rotate(-degrees, up) * eye;
}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
	vec3 axisr = glm::cross(eye, up);
	eye = Transform::rotate(-degrees, axisr) * eye;
	up = Transform::rotate(-degrees, axisr) * up; 
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{
  mat4 ret;
	//Center is (0,0,0).
	//Have position of eye and up vector...
	vec3 w = glm::normalize(eye - vec3(0,0,0));
	vec3 u = glm::normalize(glm::cross(up, w));
	vec3 v = glm::normalize(glm::cross(w, u));
	mat4 rotation = mat4(vec4(u, 0), vec4(v, 0), vec4(w, 0), vec4(0, 0, 0, 1));
	mat4 translation = mat4(vec4(1, 0, 0, -eye.x), vec4(0, 1, 0, -eye.y), vec4(0, 0, 1, -eye.z), vec4(0, 0, 0, 1));
	//GLM and OpenGL stores matrices in column major order ... WTF!
	ret =  glm::transpose(rotation) * glm::transpose(translation);
  return ret;
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // New, to implement the perspective transform as well.  
  return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement scaling 
  return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement translation 
  return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
  vec3 x = glm::cross(up,zvec); 
  vec3 y = glm::cross(zvec,x); 
  vec3 ret = glm::normalize(y); 
  return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
