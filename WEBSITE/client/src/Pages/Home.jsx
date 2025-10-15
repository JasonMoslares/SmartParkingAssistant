import React, { useEffect, useState } from 'react'
import { Link, useParams } from 'react-router-dom'
import { fetchData, handleDelete } from '../API'
import { Space, Typography, Card, Statistic } from 'antd'
import { Car } from 'lucide-react'
import '../index.css';

function Home(){
    const [dataSource, setDataSource] = useState([])

    const {id} = useParams;

    useEffect(()=> {
        fetchData(setDataSource);

        const interval = setInterval(() => {
            fetchData(setDataSource);
        }, 2000);

        return () => clearInterval(interval);
    }, [])

    

    const statusColors = {
        Vacant: { color: 'green', bg: 'rgba(0,255,0,0.25)' },
        Leaving: { color: 'orange', bg: 'rgba(255,165,0,0.25)' },
        Parked: { color: 'red', bg: 'rgba(245, 52, 52, 0.25)' },
    };

    return (
        <div className='home-container'>
            <div className='dashboard-form'>
                <Space size={20} direction='vertical'>
                    <Typography.Title className="dashboard-title">Parking Lot Monitor</Typography.Title>
                    <Link to="/create" className="createButton">Create +</Link>
                    <Space direction='horizontal' wrap>
                        {dataSource.map((lot) => {
                        const { color, bg } = statusColors[lot.status]
                        return(
                            <DashboardCard key={lot.id}
                                            icon={<Car style={{color: color,
                                                        backgroundColor: bg,
                                                        borderRadius: 20,
                                                        fontSize: 24,
                                                        padding: 8}}/>}
                                            title={lot.parking_name}
                                            lotId={lot.id}
                                            value={lot.status}
                                            onDelete={() => {
                                                handleDelete(lot.id);
                                                setDataSource(currentLot => currentLot.filter(item => item.id !== lot.id))
                                            }}/>
                        );
                    })}
                    </Space>
                </Space>
            </div>
       </div>
    );

}

function DashboardCard({title, lotId, value, icon, onDelete}) {
    return(
        <Card className="dashboard-card">
            <Space direction="vertical">
                <div className="card-header">
                    <div className="card-icon">{icon}</div>
                    <Typography.Text className="card-title">{title}</Typography.Text>
                </div>
                <Statistic value={value} />
                <Space direction="horizontal">
                    <Link className="editButton" to={`/edit/${lotId}`}>Edit</Link>
                    <button className="deleteButton" onClick={onDelete}>Delete</button>
                </Space>
            </Space>
        </Card>
    );
}

export default Home;
