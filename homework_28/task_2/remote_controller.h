#ifndef REMOTE_CONTROLLER_H

#define REMOTE_CONTROLLER_H

class RemoteController
{
	public:
		/*RemoteController ctor/dtor*/

		RemoteController();
		virtual ~RemoteController();

		/*RemoteController methods*/
		virtual void	turnOn() = 0;
		virtual void	turnOff() = 0;
};

#endif // REMOTE_CONTROLLER_H