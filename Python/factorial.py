def factorial(n: int) -> int:
	"""
	Calculate the factorial of a given number using recursion.
	
	Args:
		n (int): The number to calculate factorial for
		
	Returns:
		int: The factorial of the input number
		
	Raises:
		ValueError: If input is negative
	"""
	# Base cases
	if n < 0:
		raise ValueError("Factorial is not defined for negative numbers")
	if n == 0 or n == 1:
		return 1
	
	# Recursive case
	return n * factorial(n - 1)

# Example usage
if __name__ == "__main__":
	try:
		num = 5
		result = factorial(num)
		print(f"Factorial of {num} is: {result}")
	except ValueError as e:
		print(f"Error: {e}")