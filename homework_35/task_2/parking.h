#ifndef PARKING_H

# define PARKING_H

class	Parking
{
	private:
		int	capacity;
		int	occupied;
		int	*slots;

		Parking();
		Parking(const Parking &other) = delete;
		Parking(Parking &&other) = delete;
		Parking	&operator=(const Parking &other) = delete;
		Parking	&operator=(Parking &&other) = delete;

	public:
		~Parking();
		bool			parkCar(int slot);
		bool			removeCar(int slot);
		int				getAvailableSlots() const;
		static Parking	&getInstance();
};

#endif // PARKING_H