#ifndef REMOTE_CONTROLLER_H

#define REMOTE_CONTROLLER_H

class	RemoteController
{
	public:
		/*RemoteController ctor/dtor*/
		RemoteController();
		virtual ~RemoteController();

		/*RemoteController methods*/
		virtual void	turnOn() = 0;
		virtual void	turnOff() = 0;
		virtual void	increaseVolume(int volume) = 0;
		virtual void	decreaseVolume(int volume) = 0;
		virtual void	mute() = 0;
};

class	TVRemoteController : public RemoteController
{
	private:
		bool	is_on;
		bool	is_muted;
		int		before_mute_volume;
		int		volume_level;
	public:
		/*TVRemoteController ctor/dtor*/
		TVRemoteController();
		~TVRemoteController() override;

		/*TVRemoteController methods*/
		void	turnOn() override;
		void	turnOff() override;
		void	increaseVolume(int volume) override;
		void	decreaseVolume(int volume) override;
		void	mute() override;
};

class	ACRemoteController : public RemoteController
{
	private:
		bool	is_on;
		int		volume_level;
	public:
		/*ACRemoteController ctor/dtor*/
		ACRemoteController();
		~ACRemoteController() override;

		/*ACRemoteController methods*/
		void	turnOn() override;
		void	turnOff() override;
		void	increaseVolume(int volume) override;
		void	decreaseVolume(int volume) override;
		void	mute() override;
};

class	CarRemoteController : public RemoteController
{
	private:
		bool	is_locked;
	public:
		/*CarRemoteController ctor/dtor*/
		CarRemoteController();
		~CarRemoteController() override;

		/*CarRemoteController methods*/
		void	turnOn() override;
		void	turnOff() override;
		void	increaseVolume(int volume) override;
		void	decreaseVolume(int volume) override;
		void	mute() override;
};

#endif // REMOTE_CONTROLLER_H